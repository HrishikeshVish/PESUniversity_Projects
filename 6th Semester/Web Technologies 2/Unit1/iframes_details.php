<?php
	extract($_GET);
	if($srn=="SRN1"){
		$out = "name:name gpa:4";
	}
	else if($srn=="SRN2"){
		$out = "name:name2 gpa:2";
	}
	else{
		$out="name:NULL gpa:undef";
	}
	echo "<html>";
	echo "<script>";
	echo "parent.obj.updateDetails('$out')";
	echo "</script>";
	echo "</html>";
?>
