<?php
	$oldtime = filemtime("data.txt");
	ob_start();
	ob_flush();
	flush();

	while(true){
		
		clearstatcache();
		$newtime = filemtime("data.txt");
		if($newtime>$oldtime){
			$file = fopen("data.txt", "r");
			$data = fread($file, filesize("data.txt"));
			echo "Your Friend Says ".$data." at ".date("H:i:s", $newtime)."\n";
			$oldtime = $newtime;
			ob_flush();
			flush();
			
			clearstatcache();
		}
		sleep(3);
	}

?>