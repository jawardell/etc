"use strict";
var pers_mat,
	rot_mat, 
	scale_mat, 
	trans_mat, 
	fov,
	angle,
	sx,
	sy, 
	sz,
	tx,
	ty,
	tz,
	canvas,
	score,
	keys;
	
window.onload = function init() {
	//init transformation values
	fov = 60;
	angle = 0;
	angle = angle * Math.PI / 180.0;
	sx = 1;
	sy = 1;
	sz = 1;
	tx  0; 
	ty = 0; 
	tz = 0; 
	
	
	
	
	//INIT MATRICES
	
	
	//init perspective matrix
	pers_mat = [];
	for(var i = 0; i < 3; i++) pers_mat[i] = [];
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			pers_mat[i][j] = 0;
		}
	}
	pers_mat[0][0] = 1;
	pers_mat[1][1] = 1;
	pers_mat[2][2] = 1;
	pers_mat[3][3] = 1;
	pers_mat[3][2] = 1/fov;
	
	
	//init rotation matrix
	rot_mat = [];
	for(var i = 0; i < 3; i++) rot_mat[i] = [];
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			rot_mat[i][j] = 0;
		}
	}
	rot_mat[0][0] = Math.cos(angle);
	rot_mat[0][1] = -Math.sin(angle);
	rot_mat[1][0] = Math.sin(angle);
	rot_mat[1][1] = Math.cos(angle);
	rot_mat[3][3] = 1;
	
	
	
	//init scale matrix
	scale_mat = [];
	for(var i = 0; i < 3; i++) scale_mat[i] = [];
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			scale_mat[i][j] = 0;
		}
	}
	scale_mat[0][0]	= sx;
	scale_mat[1][1] = sy;
	scale_mat[2][2] = sz;
	scale_ mat[3][3] = 1;
	
	
	
	//init translation matrix
	trans_mat = [];
	for(var i = 0; i < 3; i++) trans_mat[i] = [];
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			trans_mat[i][j] = 0;
		}
	}
	trans_mat[0][3] = tx;
	trans_mat[1][3] = ty;
	trans_mat[2][3] = tz;
	trans_mat[0][0] = 1;
	trans_mat[1][1] = 1;
	trans_mat[2][2] = 1;
	trans_mat[3][3] = 1;
	
	
	//init other values
	canvas = document.getElementById("thecanvas");
	score = document.getElementById("score");
	keys = [];
	
	//listen for key inputs
	window.addEventListener('keydown', function(event) {
		keys[event.keyCode] = true;
		
	});
	
	window.addEventListener('keyup', function(event) {
		keys[event.keyCode] = false;
	});
}


function initGame() {
	
	
}


function updatePerspective(new_fov) {
	fov = new_fov;
	pers_mat[3][2] = fov;
	
}

function updateRotation(new_angle) {
	angle = new_angle;
	rot_mat[0][0] = Math.cos(angle);
	rot_mat[0][1] = -Math.sin(angle);
	rot_mat[1][0] = Math.sin(angle);
	rot_mat[1][1] = Math.cos(angle);
}

function updateScale(new_sx, new_sy, new_sz) {
	sx = new_sx;
	sy = new_sy;
	sz = new_sz;
	scale_mat[0][0]	= sx;
	scale_mat[1][1] = sy;
	scale_mat[2][2] = sz;
}

function updateTranslation(new_tx, new_ty, new_tz) {
	tx = new_tx;
	ty = new_ty;
	tz = new_tz;
	trans_mat[0][3] = tx;
	trans_mat[1][3] = ty;
	trans_mat[2][3] = tz;
}






