function doPart1() {
	//assume A is 4 by 4 and B is 4 by 4
	// if A is n X m , B is m X l, then C is n X l
	//thus, in this case, C is a 4 by 4 matrix
	var A = [];
	for(var i = 0; i < 4; i++) A[i] = [];
	var B = [];
	for(var i = 0; i < 4; i++) B[i] = [];
	var C = [];
	for(var i = 0; i < 4; i++) C[i] = [];

	//gather matrix data from document, see function gatherMatrix below
	gatherMatrix("a", A.length, 4, A);
	gatherMatrix("b", B.length, 4, B);

	//initialize values in final matrix to 0
	for(var i = 0; i < 4; i++) {
		for(var j = 0; j < 4; j++) {
			C[i][j] = 0.0;
		}
	}


	//perform matrix multiplication, see funtion multiply below
	C = multiply(A, B);

	//put computed data into C, see function fillSolnMatrix below
	fillSolnMatrix("c", C.length, C[0].length, C);

}


function doPart2() {
	var D = [];
	for(var i = 0; i < 4; i++) D[i] = [];
	var E = [];
	for(var i = 0; i < 4; i++) E[i] = [];
	var F = [];
	for(var i = 0; i < 4; i++) F[i] = [];

	//initialize values in final matrix to 0
	for(var i = 0; i < 4; i++) {
		for(var j = 0; j < 1; j++) {
			F[i][j] = 0.0;
		}
	}
	
	//gather matrix data from document, see function gatherMatrix below
	gatherMatrix("d", D.length, 4, D);
	gatherMatrix("e", E.length, 1, E);


	//compute matrix multiplication, see function multiply below
	F = multiply(D, E);


	//put computed data into F, see function fillSolnMatrix below
	fillSolnMatrix("f", F.length, F[0].length, F);
	
}




function gatherMatrix(type, row, col, matrix) {
	for(var i = 0; i < row; i++) {
		for(var j = 0; j < col; j++) {
			var loc = type + i.toString() + j.toString();
			matrix[i][j] = isNaN(parseFloat(document.getElementById(loc).value)) ? " " 
				: parseFloat(document.getElementById(loc).value);
		}
	}

}

function fillSolnMatrix(type, row, col, matrix) {
		for(var i = 0; i < row; i++) {
			for(var j = 0; j < col; j++) {
				var loc = type + i.toString() + j.toString();
				if(!isNaN(document.getElementById(loc).value)) {
					document.getElementById(loc).value = matrix[i][j].toString();
				} else {		
					document.getElementById(loc).value = " ";
				}
			}
		}
}


function multiply(matrix1, matrix2) {
	var areConformable = Math.abs(matrix1[0].length - matrix2.length) < Number.EPSILON;

	var matrix3 = [];
	for(var i = 0; i < matrix1.length; i++) matrix3[i] = [];


	for(var i = 0; i < matrix1.length; i++) {
		for(var j = 0; j < matrix2[0].length; j++) {
			matrix3[i][j] = 0;
		}
	}


	if(areConformable) {
		//perform naive matrix multiplication, O(n^3)
		for(var x = 0; x < matrix1.length; x++) {
			for(var y = 0; y < matrix2[0].length; y++) {
				for(var z = 0; z < matrix1[0].length; z++) {
					matrix3[x][y] += matrix1[x][z] * matrix2[z][y];
				}
			}
		}
		return matrix3;

	} else {
		document.getElementById("msg1").innerHTML = "the matrices are not conformable.";
	}
}



function showYes() {
	document.getElementById("yesdiv1").style.visibility='visible';
}
