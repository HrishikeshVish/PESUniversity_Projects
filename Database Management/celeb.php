<?php
// Start the session
session_start();
include('config.php');

if (isset($_GET['id'])) {
  $id = $_GET['id'];
  $query = mysqli_query($connection, "SELECT * FROM CELEBRITY WHERE ID=$id");

                  $row = mysqli_fetch_assoc($query);
                  $name = $row["NAME"];
                  $gender = $row["GENDER"];
                  $title = $row["JOB_TITLES"];
                  $bio = $row["BIO"];
                  $location = $row["BIRTH_LOC"];
                  $gender_list = ["Male", "Female"];
} else {
    header("location: movies.php");
}
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">

  <head>
    <meta charset="utf-8">
    <link href="https://fonts.googleapis.com/css?family=Google+Sans:400,400i,500,500i,700,700i|Google+Sans+Display:400,400i,500,500i,700,700i&amp;subset=all" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <style media="screen">
      html, body {
        height: 100%;
      }

      body {
        padding: 100px;
        font-family: Product Sans;
        color: #454545;
        font-size: 2em;
      }

      a {
        text-decoration: none;
        color: inherit;
      }

      .details {
        margin: auto;
        padding-bottom: 50px;
      }
    </style>
    <title><?php echo $name; ?></title>
  </head>

  <body oncontextmenu="return false;" ondragstart="return false;" ondrop="return false;" class="mdc-typography">
    <link rel="stylesheet" href="bundle.css">
    <div class="details">
      <h1 class="mdc-typography mdc-typography--headline1 headline"><?php echo "$name"; ?></h1>
      <h2 class="mdc-typography mdc-typography--headline2 headline"><?php echo $title; ?></h2>
      <h3 class="mdc-typography mdc-typography--headline3 headline"><?php echo "$gender_list[$gender] · $location"; ?></h3>
      <br><br>
      <?php echo $bio; ?><br>

      <br><br>

      <h2 class="mdc-typography mdc-typography--headline2 headline">Known For</h2>
      <ul class="mdc-list">
      <?php
          $query = mysqli_query($connection, "SELECT * FROM ACTED_IN WHERE CELEB_ID=$id");

              while ($row = mysqli_fetch_assoc($query)) {
                $movieID = $row["MOVIE_ID"];
                $role = $row["ROLE"];
                $movie_name = mysqli_fetch_assoc(mysqli_query($connection, "SELECT NAME FROM MOVIE WHERE ID=$movieID"))["NAME"];

                  echo "<h2><li class='mdc-list-item' onclick='location.href=\"movie.php?id=$movieID\";'><span class='mdc-list-item__text'>$movie_name · $role</span></li></h2>";
              }
        ?>
      </ul>
      <br><br>

      <button class="mdc-button mdc-button--outlined" onclick="location.href='movies.php';">
        <span class="mdc-button__label">Back</span>
      </button>
    </div>
    <script src="bundle.js"></script>
  </body>
  <script type="text/javascript">
    window.onload = function() {
      document.body.className = "mdc-typography"
    }
  </script>
</html>
