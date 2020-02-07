<?php
	set_time_limit(0);
	for($i=0;$i<100;$i++){
		$file = fopen("scores.txt", "w");
		$out = rand(0, 100)." ".rand(0, 100)." ".rand(0,100);
		fwrite($file, $out);
		fclose($file);
		sleep(10);
	}