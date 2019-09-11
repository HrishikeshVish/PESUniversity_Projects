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
    <h1 align="center">Enter Celebrity Details</h1>
    <form style="text-align: center;" method="POST" action="enterCeleb.php">
        <br><input class="in" type="text" name="name" placeholder=" Celebrity Name" required><br>
        <br><label style="font-size: 20px;">Gender :
            <select style="padding: 10px; width: 80px; border-radius: 5px;" name="gender">
                <option value="0">M</option>
                <option value="1">F</option>
            </select>
        </label><br>
        <br><input class="in" type="textarea" name="job_titles" placeholder="Job titles" rows="3" cols="50" required><br>
        <br><input class="in" type="textarea" name="bio" placeholder="Bio" rows="10" col="50"><br>
        <br><input class="in" type="text" name="birth_loc" placeholder="Country" required><br>
        <br><input class="but" type="submit" name="submit" value="submit"><br>
    </form>
</body>

</html>
<?php
if($_POST) {
        if (mysqli_num_rows(mysqli_query($connection, "SELECT * FROM `CELEBRITY` WHERE NAME='".$_POST['name']."' ")) == 0) {
                $result = mysqli_query($connection, "SELECT * FROM `CELEBRITY`;");
                $num_rows = mysqli_num_rows($result) + 1;
                echo $_POST["gender"];
                $sql = "INSERT INTO `CELEBRITY` VALUES(?, ?, ?, ?, ?, ?);";
                $gender = ((int)$_POST["gender"]);
                $stmt = mysqli_prepare($connection, $sql);
                mysqli_stmt_bind_param($stmt, "dsdsss", $num_rows, $_POST["name"], $gender, $_POST["job_titles"], $_POST["bio"], $_POST["birth_loc"]);
                mysqli_stmt_execute($stmt);
                echo mysqli_stmt_error($stmt);
                echo "Success!";
            }
        }
?> 
