"use strict"; 

var NRSTARS = 200;

var canvas = document.getElementById("canvas");
var context = canvas.getContext("2d");
context.fillStyle = '#000000';
var width = canvas.width;
var height = canvas.height;
var direction;
var inc = 0;




applyWindowToViewportTransformation(-1,1,-1,1,true);
    /**	Textbook function
     *
     * Sets up a transformation in the graphics context so that th54,e canvas will
     * show x-values in the range from left to right, and y-values in the range
     * from bottom to top.  If preserveAspect is true, then one of the ranges
     * will be increased, if necessary, to account for the aspect ratio of the
     * canvas.  This function sets the global variable pixelsize to be the
     * size of a pixel in the new coordinate system.  (If preseverAspect is
     * true, pixelSize is the maximum of its horizontal and vertical sizes.)
     */
	 
    function applyWindowToViewportTransformation(left,right,bottom,top,preserveAspect) {
        var displayAspect, windowAspect;
        var excess;
        if (preserveAspect) {
            // Adjust the limits to match the aspect ratio of the drawing area.
            displayAspect = Math.abs(canvas.height / canvas.width);
            windowAspect = Math.abs(( top-bottom ) / ( right-left ));
            if (displayAspect > windowAspect) {
                // Expand the viewport vertically.
                excess = (top-bottom) * (displayAspect/windowAspect - 1)
                top = top + excess/2
                bottom = bottom - excess/2
            }
            else if (displayAspect < windowAspect) {
                // Expand the viewport vertically.
                excess = (right-left) * (windowAspect/displayAspect - 1)
                right = right + excess/2
                left = left - excess/2	
            }
        }
        context.scale( canvas.width / (right-left), canvas.height / (bottom-top) )
        context.translate( -left, -top );
    }  // end of applyWindowToViewportTransformation()

function perspective ( f ) {

	var result = new Array();
	for(var i = 0;i<4; i++) 
		result[i] = new Array();
	for(var i = 0; i<4; i++) for(var j = 0; j<4; j++) result[i][j] = 0;

	// create simple perspective matrix here by populating result	

	result[0][0] = 1;
	result[1][1] = 1;
	result[2][2] = 1;
	result[3][3] = 1;
	result[3][2] = 1.0/f;
	
	
	var res = math.matrix(result)
	return res ;
}

function rotateZ( angle ) {
	var a =  angle * Math.PI / 180.0 ;
	var result = new Array();
	for(var i = 0;i<4; i++) 
		result[i] = new Array();
	for(var i = 0; i<4; i++) for(var j = 0; j<4; j++) result[i][j] = 0;
	
	// create rotation around Z axis 
	
	
	result[0][0] = Math.cos(angle);
	result[0][1] = -Math.sin(angle);
	result[1][0] = Math.sin(angle);
	result[1][1] = Math.cos(angle);
	result[3][3] = 1;
	
	var res = math.matrix(result) // this uses mathjs 
	return res;
}



// create array of object positions
init();
var r;
var objects, T;

function init() {



	//create perspective projection matrix
	T = perspective(1);
	
	
	//create objects
	objects = new Array();
	for(var i = 0; i<NRSTARS; i++) 
	{
		var location = math.matrix([(Math.random() * 2 - 1) * 40, (Math.random() * 2 - 1)*40, Math.random() * 255, 1]); // each location is a 4x1 vertex
		objects.push(location);
	}

	document.addEventListener("keydown", doKeyDown, false);
    document.addEventListener("keyup", doKeyUp, false);

    document.getElementById('myslider').oninput = function() {
		var newFocal = this.value; // TODO: implement logic that updates the projection matrix
			T = perspective(newFocal);

	}

	// start clock
	if (!window.requestAnimationFrame) { // This is for Internet Explorer 9
		window.requestAnimationFrame = function(callback) {
		        setTimeout(callback, 1000/60);    
		}
	}
	requestAnimationFrame(display);
	display();
}


function doKeyUp(evt) {
}

function doKeyDown(evt) {
        var code = evt.keyCode;  // Numerical code for key that was pressed.
		direction = code;
        switch (code) {
		case 37:  // left arrow key
			break;
		case 39:  // right arrow key
		    break;
		case 38:  // up arrow key
		    break;
		case 40:  // down arrow key
		    break;
		default:
		    break;
        }
}
    


function rgbToHex(r, g, b) {
    return "#" + ((1 << 24) + (r << 16) + (g << 8) + b).toString(16).slice(1);
}

// this function plots a "star" in 2d and adjusts the color
// using the depth 
function setPixel(x, y, depth) {
	
	context.fillStyle = "#00000";
	
	var red = 255 - (depth); //TODO: adjust red as a function of depth (closer stars are brighter) 
	
	
	context.beginPath();
	context.strokeStyle = rgbToHex(red, 0, 0);
	context.lineWidth = 0.004;
	context.rect(x, y, 0.01, 0.01);
	context.closePath();
	context.stroke();
}


// game loop function 
function display()
{

	
	
	// for all stars (objects), apply rotation, perspective transformation, normalize by w and draw
	
	// matrix multiplication to be done with Mathjs  (e.g.: p_prime = math.multiply(M, p), where M is a 4x4 matrix and p is a 4x1 vector
	

	context.fillRect(-1,-1,2,2); // clear the view-port
	
	for(var i = 0; i<objects.length; i++) {
	
	
		//create rotation matrix
		
		r = rotateZ(0);
		
		
		inc += .00003;
		
		if(direction == 37){
		
			r = rotateZ(inc);
		}
	
		if(direction == 39) {
			r = rotateZ(-inc);

		}

		
		objects[i] = math.add(objects[i], math.matrix([0, 0, -1, 0]));
		if(objects[i].subset(math.index([2]))<1) {
			objects[i] = math.add(objects[i], math.matrix([0, 0, 255, 0]))	
		}
		
		
		var tP = objects[i];
		
		
		tP = math.multiply(T, tP);
		
		tP = math.multiply(r, tP);
		
		tP = math.divide(tP.subset(math.index([0, 1, 2])), tP.subset(math.index([3])));
		
		var x = tP.subset(math.index([0]));
		var y = tP.subset(math.index([1]));
		
		var z = objects[i].subset(math.index([2]));
		
		setPixel(x, y, z);
		
}
	
	

	


	requestAnimationFrame(display);
}