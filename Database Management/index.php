<?php
// Start the session
session_start();
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">

  <head>
    <meta charset="utf-8">
    <title>PES MOVIE DB</title>
    <link href="https://fonts.googleapis.com/css?family=Google+Sans:400,400i,500,500i,700,700i|Google+Sans+Display:400,400i,500,500i,700,700i&amp;subset=all" rel="stylesheet">
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <style media="screen">
      html,
      body {
        height: 100%;
      }

      body {
        display: flex;
        text-align: center;
      }

      .main {
        margin: auto;
      }

      h1 {
        color: #5c5c5c;
      }

      .mdc-button {
        margin: 0px 50px 0px 50px;
      }
    </style>
  </head>

  <body class="mdc-typography">
    <div class="main">
      <link rel="stylesheet" href="bundle.css">
      <h1 class="mdc-typography mdc-typography--headline1 headline">Welcome to PES-MDB!</h1>
      <button class="mdc-button mdc-button--outlined" onclick="location.href='movies.php';">
        <span class="mdc-button__label">MOVIES</span>
      </button>
      <button class="mdc-button mdc-button--outlined" onclick="location.href='crew.php';">
        <span class="mdc-button__label">CREW</span>
      </button>
      <button class="mdc-button mdc-button--outlined" onclick="location.href='celebs.php';">
        <span class="mdc-button__label">CELEBS</span>
      </button>
    </div>
    <script src="bundle.js"></script>
  </body>

</html>
