<?php
	ob_start();
	for($i=0;$i<10;$i++){
		echo 'Count '.$i."<br/>";
		ob_flush(); // Pushes echo statements from PhP buffer. Clears the buffer. //May not work in firefox since the browser has its own buffer along with these two. 
		flush();
		sleep(3);
	}

?>
