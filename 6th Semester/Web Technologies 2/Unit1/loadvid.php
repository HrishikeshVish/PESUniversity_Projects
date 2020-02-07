<?php
	header("Content-type:video/mp4");
	$file = fopen("C:\\Users\\Hrishi\\Pictures\\Rock\\Guns N' Roseless 2.jpg", "r");
	$data = fread($file, filesize("C:\\Users\\Hrishi\\Pictures\\Rock\\Guns N' Roseless 2.jpg"));
	//$file = fopen("C:\\Users\\Hrishi\\Videos\\TV\\One Tree Hill\\Season 01\\One Tree Hill - [1x01] - Pilot.avi", "r");
	//$data = fread($file, filesize("C:\\Users\\Hrishi\\Videos\\TV\\One Tree Hill\\Season 01\\One Tree Hill - [1x01] - Pilot.avi"));
	echo $data;

?>
