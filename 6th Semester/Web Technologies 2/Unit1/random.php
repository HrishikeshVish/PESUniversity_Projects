<?php
	extract($_POST);


	if(strcmp($atname, "Ronaldo") == 0){

		$res = ["name"=>$atname, "sport"=>"Soccer", "country"=>"Portugal"];


	}
	if(strcmp($atname, "Kawhi") == 0){
		$res = ["name"=>$atname, "sport"=>"basketball", "country"=>"USA"];

	}
	if(strcmp($atname, "Ginobili")==0){
		$res = ["name"=>$atname, "sport"=>"basketball", "country"=>"Argentina"];
	}
	echo json_encode($res);


?>