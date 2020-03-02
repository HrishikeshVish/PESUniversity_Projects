<?php
	header("Content-type: text/event-stream");
	extract($_GET);
	
		$res = array();
	while(true){
	$oldtime = $time;
	clearstatcache();

	
	if(strcmp("User1", $user) == 0){
		$check = "User2.txt";
		
	}
	else{
		$check = "User1.txt";
	}
	$newtime  = filemtime($check);
	if($newtime > $oldtime){
		$arr = file($check);
		$msg = array_pop($arr);
		$res["data"] = $msg;
		$res["time"] = $newtime;
		$out = json_encode($res);
		
		echo "data: ".$out."\n\n";
		$oldtime = $newtime;
		break;
	}
	else{
		sleep(1);
		continue;
	}
	}
?>
