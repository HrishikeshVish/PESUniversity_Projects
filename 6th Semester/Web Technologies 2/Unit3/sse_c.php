<?php
	header("Content-type:text/event-stream");
	ob_start();
	for($i=0;$i<5;$i++){
		//Event classified as a message
		echo "event:ev1\n";
		echo"retry:7000\n";
		echo "data:student".$i."\n\n";
		echo"data:Count".$i."\n\n";
		ob_flush();
		flush();
		sleep(3);
	}
	echo "event:close\n";
	echo "data:File Done\n";

?>