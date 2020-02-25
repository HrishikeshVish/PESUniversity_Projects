<?php
	extract($_GET);
	$oldtime = $t;
	$res = array();
	while(true){
		clearstatcache(); // prevent cache from interfering. Otherwise, it will return older versions of the document stored in cache. 
		$newtime = filemtime("data.txt");
		if($newtime >$oldtime){
			$file = fopen("data.txt", "r");
			$data = fread($file, filesize("data.txt"));
			$res["data"] = $data;
			$res["time"] = $newtime;
			echo json_encode($res);
			break;
		}
		else{
			sleep(3);
			continue;
		}

	}
?>