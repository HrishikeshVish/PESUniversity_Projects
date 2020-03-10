<?php
	extract($_GET);
	$res = array();
	if($srn == 99){
		$data = array();
		$data['name'] = "ABC";
		$data["CGPA"] = 10;
		$data["branch"] = "RRRR";
		$res['data'] = $data;
		$res['status'] = 200;
		$res["message"] = "OK";
	}
	else{
		$data = null;
		$res['data'] = $data;
		$res['status'] = 404;
		$res['message'] = "Not Found";

	}
	if($format == 'json'){
		echo json_encode($res);
	}
	else{
		echo $format."Not ";
	}
?>