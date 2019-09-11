<?php
// Start the session
session_start();
include('config.php');

if (isset($_GET['id'])) {
  $id = $_GET['id'];
  $query = mysqli_query($connection, "SELECT * FROM MOVIE WHERE ID=$id");

                  $row = mysqli_fetch_assoc($query);
                  $name = $row["NAME"];
                  $rating = $row["RATING"];
                  $year = $row["RELEASE"];
                  $language = $row["LANGUAGE"];
                  $director = $row["DIRECTOR"];
                  $location = $row["LOCATION"];
                  $runtime = $row["RUNTIME"];
                  $mpaa = $row["MPAA_RATING"] - 1;
                  $budget = $row["BUDGET"];
                  $mpaa_list = ["G", "PG", "PG-13", "R", "NC-17"];
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
      <h1 class="mdc-typography mdc-typography--headline1 headline"><?php echo "$name ($year)"; ?></h1>
      <h2 class="mdc-typography mdc-typography--headline2 headline"><?php echo $rating; ?><i class="material-icons">star_rate</i></h2>
      <h3 class="mdc-typography mdc-typography--headline3 headline"><?php echo "$mpaa_list[$mpaa] · $language"; ?></h3>
      <br><br>
      Directed by <?php echo $director; ?><br>
      Filmed in <?php echo $location; ?><br><br>
      Runtime: <?php echo $runtime; ?> minutes<br>
      Budget: $<?php echo $budget; ?> million<br>

      <br><br>

      <h2 class="mdc-typography mdc-typography--headline2 headline">Cast</h2>
      <ul class="mdc-list">
      <?php
          $query = mysqli_query($connection, "SELECT * FROM ACTED_IN WHERE MOVIE_ID=$id");

              while ($row = mysqli_fetch_assoc($query)) {
                $celebID = $row["CELEB_ID"];
                $role = $row["ROLE"];
                $celeb_name = mysqli_fetch_assoc(mysqli_query($connection, "SELECT NAME FROM CELEBRITY WHERE ID=$celebID"))["NAME"];

                  echo "<h2><li class='mdc-list-item' onclick='location.href=\"celeb.php?id=$celebID\";'><span class='mdc-list-item__text'>$celeb_name · $role</span></li></h2>";
              }
        ?>
      </ul>
      <br><br>

      <h2 class="mdc-typography mdc-typography--headline2 headline">Showtimes</h2>
      <ul class="mdc-list">
      <?php
          $query = mysqli_query($connection, "SELECT * FROM `SHOW` WHERE MOVIE_ID=$id");

              while ($row = mysqli_fetch_assoc($query)) {
                $showID = $row["ID"];
                $screenID = $row["SCREEN_ID"];
                $res1 = mysqli_fetch_assoc(mysqli_query($connection, "SELECT * FROM SCREEN WHERE ID=$screenID"));
                $screenName = $res1["NAME"];
                $screenLoc = $res1["LOCATION"];

                  echo "<li><h2>$screenName - $screenLoc</h2><ul class='mdc-list'>";
                  $query1 = mysqli_query($connection, "SELECT DATE_FORMAT(`TIME`, '%a, %b %d - %l:%i %p') AS F_TIME FROM SHOWTIME WHERE SHOW_ID=$showID");

              while ($row1 = mysqli_fetch_assoc($query1)) {
                $showTime = $row1["F_TIME"];
                echo "<li>$showTime</li>";
              }
                  echo "</ul></li>";
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
