
var canvas = document.getElementById("canvas");
var context = canvas.getContext("2d");

canvas.addEventListener("mousedown", handleMouseDown);
canvas.addEventListener("mousemove", handleMouseMove);
canvas.addEventListener("mouseup", handleMouseUp);

  
var p0 = {x: 0, y:0};
var p1 = {x: 0, y:0};

 
var isdown = 0;

 
display();


function setPixel(x, y) {
	context.fillRect(x, y, 1, 1);
}
  

function handleMouseUp(event)
{
	isdown = 0;
	p1.x = event.clientX - canvas.offsetLeft;
	p1.y = event.clientY - canvas.offsetTop;
	display();
}

  

function handleMouseDown(event)
{
	isdown = 1;
	p0.x = event.clientX - canvas.offsetLeft;
	p0.y = event.clientY - canvas.offsetTop;
	display();

}

  

function handleMouseMove(event)

{
	if (isdown == 0)
		return;
	
  	p1.x = event.clientX - canvas.offsetLeft;
	p1.y = event.clientY - canvas.offsetTop;

	display();
}

//implemented from pseudocode on wikipedia page
function bresenham(p0, p1)
{
	var width = canvas.width;
	var height = canvas.height;
	if((p0.x >= (width/2)) && (p0.x <= width)) {
		if((p0.y >= 0) && (p0.y <= (height/2))) {
			if(Math.abs(p0.y) > Math.abs(p0.x)) {
				document.getElementById("quadrant").innerHTML = "point p0 exists in  octant 0";
			} else {
				document.getElementById("quadrant").innerHTML = "point p0 exists in  octant 1";
			}

		} else {
			if(Math.abs(p0.x) > Math.abs(p0.y)) {
				document.getElementById("quadrant").innerHTML = "point p0 exists in  octant 7";
			} else {
				document.getElementById("quadrant").innerHTML = "point p0 exists in  octant 6";
			}
		}
	
	} else if ((p0.x > 0) && (p0.x <= width/2)) {
		if((p0.y >= (height/2)) && (p0.y <= height)) {
			if(Math.abs(p0.y) > Math.abs(p0.x)) {
				document.getElementById("quadrant").innerHTML = "point p0 exists in octant 5";
			} else {
				document.getElementById("quadrant").innerHTML = "point p0 exists in octant 4";
			}

		} else {
			if(Math.abs(p0.x) > Math.abs(p0.y)) {
				document.getElementById("quadrant").innerHTML = "point p0 exists in octant 2";
			} else {
				document.getElementById("quadrant").innerHTML = "point p0 exists in octant 3";
			}
		
		}	
	}
	
	

	if(Math.abs(p1.y - p0.y) < Math.abs(p1.x - p0.x)) {
		if(p0.x > p1.x) {
			horizontalGradient(p1.x, p1.y, p0.x, p0.y);
//			document.getElementById("quadrant").innerHTML = "second quadrant";

		} else {
			horizontalGradient(p0.x, p0.y, p1.x, p1.y);
//			document.getElementById("quadrant").innerHTML = "first quadrant";
		}
	} else { 
		if(p0.y > p1.y) {
			verticalGradient(p1.x, p1.y, p0.x, p0.y);
//			document.getElementById("quadrant").innerHTML = "fourth quadrant";
		} else {
			verticalGradient(p0.x, p0.y, p1.x, p1.y);	
//			document.getElementById("quadrant").innerHTML = "third quadrant";
		}
	}
}



function horizontalGradient(x0, y0, x1, y1) {
	var dx = x1 - x0;
	var dy = y1 - y0;
	var yi = 1;
	if(dy < 0) {
		yi = -1;
		dy = -dy;
	}
	var D = 2*dy - dx;
	y = y0;
	for(var x = x0; x <= x1; x++) {
		setPixel(x, y);
		if(D > 0) {
			y = y + yi;
			D = D - 2*dy;
		}
		D = D + 2*dy;
	}
	
	
}


function verticalGradient(x0, y0, x1, y1) {	
	var dx = x1 - x0;
	var dy = y1 - y0;
	var xi = 1;
	if(dx < 0) {
		xi = -1;
		dx = -dx;
	}
	D = 2*dx - dy;
	x = x0;
	for(var y = y0; y <= y1; y++) {
		setPixel(x, y);
		if(D > 0) {
			x = x + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
	}

}
  

function display()
{
	context.clearRect(0, 0, canvas.width, canvas.height);
	var dx = p1.x - p0.x;
	var dy = p1.y - p0.y;

	context.fillStyle = "#000000";
	context.strokeStyle = "#000000";
	
	bresenham(p0, p1); <!-- this should work before you turn in your assignment -->


	// this is what your algorithm SHOULD output, comment these when working on the algorithm
	//context.beginPath();
	//context.moveTo(p0.x, p0.y);
	//context.lineTo(p1.x, p1.y);
	//context.stroke();

}

  