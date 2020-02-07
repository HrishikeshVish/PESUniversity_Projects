<?php
	$file = fopen("scores.txt", "r");
	$data = fread($file, filesize("scores.txt"));
	$datatosend = trim($data);
	//$datatosend = implode(" ", $datatosend);
	//$datatosend = preg_split('/\s+/', $datatosend);
	//$out = "score1:".$datatosend[0].""
	echo $datatosend;

?>
