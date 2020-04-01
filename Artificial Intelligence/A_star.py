from datetime import datetime
import matplotlib.pyplot as plt
class Node():
    

    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position

        self.g = 0
        self.h = 0
        self.f = 0

    def __eq__(self, other):
        return self.position == other.position


def astar(maze, start, end, heuristic):
    

    
    start_node = Node(None, start)
    start_node.g = start_node.h = start_node.f = 0
    end_node = Node(None, end)
    end_node.g = end_node.h = end_node.f = 0

    
    open_list = []
    closed_list = []

    
    open_list.append(start_node)

    
    while len(open_list) > 0:

        
        current_node = open_list[0]
        current_index = 0
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index

        
        open_list.pop(current_index)
        closed_list.append(current_node)

        
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            return path[::-1] # Return reversed path

        
        children = []
        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]: # Adjacent squares

            
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])

            
            if node_position[0] > (len(maze) - 1) or node_position[0] < 0 or node_position[1] > (len(maze[len(maze)-1]) -1) or node_position[1] < 0:
                continue

            
            if maze[node_position[0]][node_position[1]] != 0:
                continue

            
            new_node = Node(current_node, node_position)

            
            children.append(new_node)

        
        for child in children:

            
            for closed_child in closed_list:
                if child == closed_child:
                    continue

            
            child.g = current_node.g + 1
            if heuristic == 0:
                #Euclidian Distance
                child.h = ((child.position[0] - end_node.position[0]) ** 2) + ((child.position[1] - end_node.position[1]) ** 2)**0.5
            elif heuristic == 1:
                #Manhattan Distance
                child.h = abs(child.position[0] - end_node.position[0]) + abs(child.position[1] - end_node.position[1])
            elif heuristic == 2:
                #Chebyschev Distance
                dx = abs(child.position[0] - end_node.position[0])
                dy = abs(child.position[1] - end_node.position[1])
                D = 1
                D2 = 1
                child.h = D *(dx + dy) + (D2 - 2*D)*min(dx, dy)
            else:
                #Octile Distance
                dx = abs(child.position[0] - end_node.position[0])
                dy = abs(child.position[1] - end_node.position[1])
                D = 1
                D2 = 2**0.5
                child.h = D *(dx + dy) + (D2 - 2*D)*min(dx, dy)                
            child.f = child.g + child.h

            
            for open_node in open_list:
                if child == open_node and child.g > open_node.g:
                    continue

            
            open_list.append(child)


def main():

    maze = [[0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
            [0, 0, 1, 1, 1, 1, 0, 0, 0, 1],
            [0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
            [1, 0, 1, 0, 1, 1, 1, 1, 0, 0],
            [0, 1, 0, 1, 0, 1, 0, 0, 1, 1],
            [1, 0, 0, 0, 1, 0, 1, 1, 0, 1],
            [0, 0, 1, 0, 1, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 1, 0, 0, 1, 1, 1],
            [0, 1, 0, 1, 1, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]]
    maze2 = [[0, 0, 1, 0, 1, 0, 0, 1, 0, 0,0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
            [0, 0, 1, 1, 1, 1, 0, 0, 1, 1,0, 1, 1, 1, 1, 1, 1, 1, 0, 1],
            [0, 0, 1, 0, 1, 0, 1, 1, 1, 0,1, 1, 1, 1, 1, 1, 1, 1, 0, 0],
            [1, 0, 1, 0, 1, 1, 1, 1, 0, 1,1, 0, 1, 0, 1, 1, 1, 1, 1, 0],
            [0, 1, 0, 1, 0, 1, 0, 0, 1, 0,0, 1, 0, 1, 0, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 1, 0, 1, 1, 0, 1,1, 0, 0, 0, 1, 1, 1, 1, 1, 1],
            [0, 0, 1, 0, 1, 1, 0, 0, 0, 0,0, 0, 1, 0, 1, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 1, 0, 0, 1, 1, 1,1, 0, 0, 0, 1, 0, 0, 1, 1, 1],
            [0, 1, 0, 1, 1, 1, 0, 0, 0, 0,0, 1, 0, 1, 1, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0,0, 0, 0, 0, 0, 0, 1, 0, 0, 0]]

    start = (0, 0)
    end = (4, 14)
    eucdist = [];
    mandist = [];
    chebdist = [];
    octdist = [];
    i = 0
    y = [1,2,3,4,5,6,7,8,9,10]
    while(i<10):
        start_t = datetime.now().microsecond
        path = astar(maze2, start, end,0)
        end_t = datetime.now().microsecond
        eucdist.append(abs(end_t-start_t))
        print("Time taken when heuristic is Euclidian distance is :" + str(end_t-start_t))
        print(path)
        print(len(path))
        start_t = datetime.now().microsecond
        path = astar(maze2, start, end, 1)
        end_t = datetime.now().microsecond
        mandist.append(abs(end_t-start_t))
        print("Time taken when heuristic is Manhattan distance is :" + str(end_t-start_t))
        print(path)
        print(len(path))
        start_t = datetime.now().microsecond
        path = astar(maze2, start, end, 2)
        end_t = datetime.now().microsecond
        chebdist.append(abs(end_t-start_t))
        print("Time taken when heuristic is Chebyschev distance is :" + str(end_t-start_t))
        print(path)
        print(len(path))
        start_t = datetime.now().microsecond
        path = astar(maze2, start, end, 3)
        end_t = datetime.now().microsecond
        octdist.append(abs(end_t-start_t))
        print("Time taken when heuristic is Octile distance is :" + str(end_t-start_t))
        print(path)
        print(len(path))
        i = i + 1
    print("Euclid distance")
    plt.plot(y, eucdist)
    plt.ylabel('Euclidian Distance')
    plt.show()
    print(eucdist)
    print("Manhattan Distance")
    plt.plot(y, mandist)
    plt.ylabel('Manhattan Distance')
    plt.show()
    print(mandist)
    print("Chebyschev Distance")
    plt.plot(y, chebdist)
    plt.ylabel('Chebyschev Distance')
    plt.show()
    print(chebdist)
    print("Octile Distance")
    plt.plot(y, octdist)
    plt.ylabel('Octile Distance')
    plt.show()
    print(octdist)

if __name__ == '__main__':
    main()