<?php
	extract($_GET);
	$file = fopen("food.txt", "r");
	$res = array();

	while(!feof($file)){
		$line = trim(fgets($file));
		if(strncasecmp($term, $line, strlen($term))==0){
			$res[] = $line;

		}
	}
	echo json_encode($res);
?>