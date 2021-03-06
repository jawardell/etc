var canvas = document.getElementById("canvas");
var context = canvas.getContext("2d");

// change the transformation stack
// NOTICE: this affects the viewport transformation
context.translate(canvas.width/2, canvas.height/2);
context.scale(canvas.width/10, canvas.height/10);
context.lineWidth=0.02;

var T, S, R; // translation, scale and rotation matrices 
var g = []; // array containing the geometry vertices 


refresh();

function initialize_empty_js_matrices() {
    T = [];
    S = [];
    R = [];
}


// this function draws axes
function draw_axes() {
    context.moveTo(-5, 0);
    context.lineTo(5, 0);
    context.stroke();
    context.moveTo(0, -5);
    context.lineTo(0, 5);
    context.stroke();
    for(var x = -5; x<=5; x+=0.5)
    {   
        context.moveTo(x, -0.1);
        context.lineTo(x, 0.1);
        context.stroke();
        context.moveTo(-0.1, x);
        context.lineTo(0.1, x);
        context.stroke();
    }   
	context.font = "1px Times New Roman";
	context.fillText("+x",3.5,0);
	context.fillText("+y",0,4.5);

} 


// this function creates the geometry
function create_geometry() {

	g = [];
    // create a square
    g.push(new Float32Array([3, 3, 1]));
    g.push(new Float32Array([-3, 3, 1]));
    g.push(new Float32Array([-3, -2, 1]));
    g.push(new Float32Array([3, -2, 1]));

	// roof
    g.push(new Float32Array([-3, -2, 1]));
    g.push(new Float32Array([0, -4.5, 1]));
    g.push(new Float32Array([3, -2, 1]));

    // create a 36 point ellipse
    for(var i = 0; i<36;i ++ )
    {   
        g.push(new Float32Array([Math.cos(i*10*Math.PI/180.0),1+1.5*Math.sin(i*10*Math.PI/180.0), 1]));
    }   
}



// this function draws the geometry
function draw_geometry() {
    //first 4 points define a square
    context.moveTo(g[0][0], g[0][1]);
    for(var i = 1; i<6; i++)
    {
        context.lineTo(g[i][0], g[i][1]);
        context.moveTo(g[i][0], g[i][1]);
    }   
    context.lineTo(g[3][0], g[3][1]);
    context.moveTo(g[3][0], g[3][1]);
    context.lineTo(g[0][0], g[0][1]);
    context.stroke();

    // rest of g are the ellipse vertices 
    context.moveTo(g[7][0], g[7][1]);
    for(var i = 7; i<g.length; i++)
    {
        context.lineTo(g[i][0], g[i][1]);
        context.moveTo(g[i][0], g[i][1]);
    }   
    context.moveTo(g[7][0], g[7][1]);
    context.lineTo(g[g.length-1][0], g[g.length-1][1]);
    context.stroke();
}




//////////////////////////////////////////////////////////////////////////////////
////////// begin here ////////////////////////////////////////////////////////////


// this is the matrix multiply function from assignment 1
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
		//document.getElementById("msg1").innerHTML = "the matrices are not conformable.";
	}
}

// this function reads the HTML input boxes and creates (populates) 
// matrices T, S, and R. Keep in mind that these have to 
// work with your multiply() function 
function create_matrices_from_HTML() {
    //first the translation
	initialize_empty_js_matrices();
	// parse the parameters from HTML input boxes
	var tx = parseFloat(document.getElementById("tx").value);
	var ty = parseFloat(document.getElementById("ty").value);
	var sx = parseFloat(document.getElementById("sx").value);
	var sy = parseFloat(document.getElementById("sy").value);
	var theta = parseFloat(document.getElementById("theta").value)
	




	// create and populate T, S and R 

	for(var i = 0; i < 3; i++) T[i] = []; 
	for(var i = 0; i < 3; i++) S[i] = [];
	for(var i = 0; i < 3; i++) R[i] = [];
    
	

	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			T[i][j] = 0.0;
		}
	}
	
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			S[i][j] = 0.0;
		}
	}
	
	for(var i = 0; i < 3; i++) {
		for(var j = 0; j < 3; j++) {
			R[i][j] = 0.0;
		}
	}

	  
	S[0][0] = sx;
	S[1][1] = sy;
	S[2][2] = 1;

	T[0][2] = tx;
	T[1][2] = ty;
	T[0][0] = 1;
	T[1][1] = 1;
	T[2][2] = 1;
	
	R[0][0] = Math.cos(theta * (Math.PI / 180.0));
	R[0][1] = -Math.sin(theta * (Math.PI / 180.0));
	R[1][0] = Math.sin(theta * (Math.PI / 180.0));
	R[1][1] = Math.cos(theta * (Math.PI / 180.0));
	R[2][2] = 1.0;



}



// this function applies the transformations (R, S and T, in that order)
// on all vertices stored in g
function apply_transforms() {
	// for all vertices in g, apply the transformations 
	
	console.log("g pre-processing");
	printMatrix(g);
	
		
	//get each vertex from g, per row
	//then multiply each vertex by rotation matrix
	for(var row = 0; row < g.length; row++) {
		var vertex = [];
		vertex[0] = [];
		vertex[1] = [];
		vertex[2] = [];
		vertex[0][0] = g[row][0];
		vertex[1][0] = g[row][1];
		vertex[2][0] = g[row][2];
		
		//apply transformation to vertex
		var vprime = multiply(R, vertex);
	
		//overwrite old vertices in G with transformed ones
		g[row][0] = vprime[0][0];
		g[row][1] = vprime[1][0]; 
		g[row][2] = vprime[2][0];
		
	}
	
	console.log("\nrotation complete\n");
	console.log("g after rotation");
	printMatrix(g);
	
	for(var row = 0; row < g.length; row++) {
		var vertex = [];
		vertex[0] = [];
		vertex[1] = [];
		vertex[2] = [];
		
		
		vertex[0][0] = g[row][0];
		vertex[1][0] = g[row][1];
		vertex[2][0] = g[row][2];
		
		//apply transformation to vertex
		var vprime = multiply(S, vertex);
	
		//overwrite old vertices in G with transformed ones
		g[row][0] = vprime[0][0];
		g[row][1] = vprime[1][0]; 
		g[row][2] = vprime[2][0];
	}
	
	console.log("\nscale complete\n");
	console.log("g after scale");
	printMatrix(g);
	
	for(var row = 0; row < g.length; row++) {
		var vertex = [];
		vertex[0] = [];
		vertex[1] = [];
		vertex[2] = [];
		
		
		vertex[0][0] = g[row][0];
		vertex[1][0] = g[row][1];
		vertex[2][0] = g[row][2];
		
		//apply transformation to vertex
		var vprime = multiply(T, vertex);
	
		//overwrite old vertices in G with transformed ones
		g[row][0] = vprime[0][0];
		g[row][1] = vprime[1][0]; 
		g[row][2] = vprime[2][0];
	}
	
	console.log("\ntranslation complete\n");
	console.log("g after translation");
	printMatrix(g);
}




//////////////////////////////////////////////////////////////////////////////////
////////// end here //////////////////////////////////////////////////////////////




// this function is called at start-up and when the user clicks "transform"
function refresh() {
    create_matrices_from_HTML();

	context.beginPath();
	context.fillStyle = "#ff0000";
	context.clearRect(-5, -5, 10, 10);
	context.fill();
	context.closePath();

	draw_axes(); console.log("here on line 342");
	create_geometry(); console.log("here on line 343");
	apply_transforms(); console.log("here on line 344");
	draw_geometry(); console.log("here on line 345");
	console.log("geometry drawn successfully");
	
}


function printMatrix(matrix) {
	var res = "";
	for(var i = 0; i < matrix.length; i++) {
		for(var j = 0; j < matrix[0].length; j++) {
			if(j == matrix[0].length - 1) {
				res += matrix[i][j] + "\n";
			} else {
				res += matrix[i][j] + " ";
			}
		}
	}
	console.log(res);
}

