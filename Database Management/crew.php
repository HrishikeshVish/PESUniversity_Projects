<?php
// Start the session
session_start();
include('config.php');
mysqli_query($connection, 'SET NAMES utf8');
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
    <title>PRODUCTION CREW</title>
  </head>

  <body oncontextmenu="return false;" ondragstart="return false;" ondrop="return false;" class="mdc-typography">
    <link rel="stylesheet" href="bundle.css">
    <div class="details">
      <h1 class="mdc-typography mdc-typography--headline1 headline">Production Crew</h1>
      <br><br>
      <ul class="mdc-list">
        <?php
          $query = mysqli_query($connection, "SELECT * FROM PRODUCTION_CREW");

              while ($row = mysqli_fetch_assoc($query)) {
                  $name = $row["CREW_NAME"];
                  $job = $row["JOB_DESCRIPTION"];

                  echo "<h2><li class='mdc-list-item'><span class='mdc-list-item__text'>$name · $job</span></li></h2>";
              }
        ?>
      </ul>
      <br><br>
      <button class="mdc-button mdc-button--outlined" onclick="location.href='index.php';">
        <span class="mdc-button__label">Home</span>
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