<?php
	
	
	$user = $_GET["user"];
	$message = $_GET["message"];
	$file = fopen($user.".txt", 'a');
	
	fwrite($file, $user.": ".$message."\n");
	
	fclose($file);

?>
