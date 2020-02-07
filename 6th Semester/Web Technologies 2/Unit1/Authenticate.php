<?php
	header("Content-type: image/jpeg");
	extract($_GET);
	if($name =="user1" || $name == "user2" || $name == "user3"){
		$im = imagecreate(1,1);
	}
	else{
		$im = imagecreate(2,2);
	}
	imagecolorallocate($im, 255, 255, 100);
	imagejpeg($im);


?>