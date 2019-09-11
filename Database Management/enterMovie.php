<?php
// Start the session
session_start();
include("config.php");
?>

<!DOCTYPE html>
<html>
<link href="form.css" rel="stylesheet" type="text/css">
<head>
                <title>Update Database</title>
</head>
<body>
                <h1 align="center">Enter Movie Details</h1>
<form style="text-align: center;" method="POST" action="enterMovie.php">
                <br><input class="in" type="text" name="name" placeholder="Movie Name" required><br>
                <br><input class="in"type="text" name="language" placeholder="Language" required><br>
                <br><input class="in"type="number" name="release" placeholder="Year of Release" min="1920" max="2019" step="1" required><br>
                <br><input class="in"type="text" name="director" placeholder="Director" required><br>
                <br><input class="in"type="text" name="producton" placeholder="Production Company" required><br>
                <br><input class="in"type="text" name="crew" placeholder="Production Crew" required><br>
                <br><input class="in"type="text" name="location" placeholder="Country" required><br>
                <br><input class="in"type="number" name="runtime" placeholder="Runtime(in mins)" required><br>
                <br><input class="in"type="number" name="budget" placeholder="Budget" required><br>
                <br><input class="in"type="number" name="rating" placeholder="Rating" step="0.1" required><br>
                <br><input class="in"type="number" name="m_rating" placeholder="MPAA Rating" required><br>
                <br><input class="but"type="submit" name="submit" value="submit"><br>
                <br><br><br><br>
</form>
</body>
</html>
<?php
if($_POST) {
        if (mysqli_num_rows(mysqli_query($connection, "SELECT * FROM `MOVIE` WHERE NAME='".$_POST['name']."' ")) == 0) {
                $result = mysqli_query($connection, "SELECT * FROM `MOVIE`;");
                $num_rows = mysqli_num_rows($result) + 1;
                $sql = "INSERT INTO `MOVIE` VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
                $stmt = mysqli_prepare($connection, $sql);
                mysqli_stmt_bind_param($stmt, "dsddsssddd", $num_rows, $_POST["name"], $_POST["rating"], $_POST["release"], $_POST["language"], $_POST["director"], $_POST["location"], $_POST["runtime"], $_POST["m_rating"], $_POST["budget"]);
                mysqli_stmt_execute($stmt);
                echo mysqli_stmt_error($stmt);
                echo "Success!";
            }
        }
?> 

