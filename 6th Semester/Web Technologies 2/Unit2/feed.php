<?php
	header("Content-type:text/xml");
	$data = file_get_contents("olympics.xml");
	echo $data;
?>