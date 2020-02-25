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
			$res= "Your Friend Says ".$data." at ".date("H:i:s", $newtime);
			$oldtime = $newtime;
			echo "<script>";
			echo "parent.obj.updateDiv('".$res."')";
			echo "</script>";
			ob_flush();
			flush();
			
			clearstatcache();
		}
		else{
			//Heartbeat function
			echo "<script>";
			echo "parent.obj.heartbeat()";
			echo "</script>";
		}
		sleep(3);
	}

?>