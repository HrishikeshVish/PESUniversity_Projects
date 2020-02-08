<?php
	extract($_GET);
	$file = fopen("scores.txt", "r");
	$data = fread($file, filesize("scores.txt"));

	$datatosend = explode(" ", $data);
	$datatosend[0] = (int)$datatosend[0];
	$datatosend[1] = (int)$datatosend[1];
	$datatosend[2] = (int)$datatosend[2];
	$datatosend[3] = (int)$datatosend[3];
	fclose($file);
	$file = fopen("scores.txt", "w");
	if($branch == "CSE" && $datatosend[0]>0){
		
		$datatosend[0] = $datatosend[0] - 1;
		
	}
	if($branch == "ECE"&& $datatosend[1]>0){
		$datatosend[1] = $datatosend[1] - 1;
	}
	if($branch == "ME"&& $datatosend[2]>0){
		$datatosend[2] = $datatosend[2] - 1;
	}
	if($branch == "BT"&& $datatosend[3]>0){
		$datatosend[3] = $datatosend[3] - 1;
	}
	
	$out = $datatosend[0]." ".$datatosend[1]." ".$datatosend[2]." ".$datatosend[3];	
	echo $out;
	fwrite($file, $out);
	fclose($file);
	#echo $datatosend[0];
?>
