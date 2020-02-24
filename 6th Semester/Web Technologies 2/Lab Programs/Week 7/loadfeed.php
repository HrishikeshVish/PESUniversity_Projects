<?php
	header("Content-type:text/XML");
	$var = file_get_contents("rss.xml");
	echo $var;
?>
