	var score = 0; 

	var food_x;
	var food_y;

	var direction = 40;

	var x_coord = 100;
	var y_coord = 100;


	
    "use strict";  // gives improved error-checking in scripts.

    var canvas;    // The canvas element on which we will draw.
    var graphics;  // A 2D graphics context for drawing on the canvas.

    var elapsedTimeMillis;  // This will be the time since the animation started;
                            // will be zero in the first frame.

    var image;

	var drawFrame = false;
	
	var allLoaded;
	
	var frameNumber;

	var startTime;
	
	var grid = [];
	
	
	var rows = 30;
	var cols = 40;
		
	
	for(var i = 0; i < rows; i++) {
				grid[i] = [];
	}
			
			
	for(var i = 0; i < rows; i++) {
		for(var j = 0; j < cols; j++) {
				grid[i][j] = 0.0;
		}
	}
	
	
    function draw() {
		frameNumber ++;
        graphics.clearRect(0,0,canvas.width,canvas.height);  // Clear the canvas, so it shows its background color.
    } // end of draw()
    
    

    function doKeyDown(evt) {
        var code = evt.keyCode;  // Numerical code for key that was pressed.
		console.log("woo!! we did it key event!");
        switch (code) {
		case 37:  // left arrow key
			direction = 37;
		    break;
		case 39:  // right arrow key
			direction = 39;
		    break;
		case 38:  // up arrow key
			direction = 38;
		    break;
		case 40:  // down arrow key
			direction = 40;
		    break;
        }
    }
    
	
	

    /**
     *  Draw one frame of the animation, and call requestAnimationFrame() to arrange
     *  for the function to be called again.
     */
    function doFrame() {
		
		
		if(x_coord >= canvas.width) {
			console.log("woah, x went too far, stopping");
			document.getElementById("report").innerHTML = "game over";
			return;
		}
		
		if(x_coord == 0) {
			console.log("woah, x went too far, stopping");
			document.getElementById("report").innerHTML = "game over";
			return;
		}
		
		
		if(y_coord == 0) {
			console.log("woah, y went too far, stopping");
			document.getElementById("report").innerHTML = "game over";
			return;
		}
		
		if(y_coord >= canvas.width) {
			console.log("woah, y went too far, stopping");
			document.getElementById("report").innerHTML = "game over";
			return;
		}
		

		// GAME LOGIC here
		
		//console.log("we are here");
		console.log("xcoord = " + x_coord);
		console.log("ycoord = " + y_coord);
		console.log("grid xcoord = " + parseInt(x_coord/40));
		console.log("grid ycoord = " + parseInt(y_coord/30));
		
		print_grid(grid);
		
		
		//grid[parseInt(x_coord/30)][parseInt(y_coord/40)] = "*";rest of snake
		grid[parseInt(x_coord/30)][parseInt(y_coord/40)] = "H";
		
		if(direction == 40) {//down
			y_coord += 7;
			graphics.clearRect(x_coord, y_coord-7, 15, 15);
			grid[parseInt(x_coord/30)][parseInt((y_coord-7)/40)] = "0";
		}
		
		
		if(direction == 37) {//left
			x_coord -= 7;
			graphics.clearRect(x_coord+7, y_coord, 15, 15);
			grid[parseInt((x_coord+7)/30)][parseInt(y_coord/40)] = "0";
		}
		
		if(direction == 39) {//right
			x_coord += 7;
			graphics.clearRect(x_coord-7, y_coord, 15, 15);
			grid[parseInt((x_coord-7)/30)][parseInt(y_coord/40)] = "0";
		}
		
		if(direction == 38) {//up
			y_coord -= 7;
			graphics.clearRect(x_coord, y_coord+7, 15, 15);
			grid[parseInt(x_coord/30)][parseInt((y_coord+7)/40)] = "0";
		}


		if(grid[parseInt(x_coord/30)][parseInt(y_coord/40)] == "F") {
			console.log("you landed on food");	
		
			document.getElementById("score").innerHTML = score;
			graphics.clearRect(food_x, food_y, 15+score*5, 15+score*5);
			score += 1;
			food_x = parseInt(Math.random()*801);
			console.log("food x = " + food_x);
			food_y = parseInt(Math.random()*601);
			console.log("food y = " + food_y);	
			grid[parseInt(food_x/30)][parseInt(food_y/40)] = 0;
			//graphics.drawImage(image,food_x,food_y);
			graphics.fillStyle =  "#FF0000";
			graphics.fillRect(food_x,food_y, 15+score*5,15+score*5);
		
			
		
		
			
			
			console.log("food_x/30 " + food_x/30);
			console.log("food_y/40 " + food_y/40);

			grid[parseInt(food_x/30)][parseInt(food_y/40)] = "F";
		}

		
		
		//if(grid[parseInt(x_coord/30)][parseInt(y_coord/40)] == "*") {
			//console.log("you ran into yourself. exiting now.");
			//return;
		//} else {
			grid[parseInt(x_coord/30)][parseInt(y_coord/40)] = "H";
			graphics.fillStyle =  "#000000";
			graphics.fillRect(x_coord,y_coord, 15,15);
		//}
		
		//graphics.clearRect(x_coord, y_coord-10,15,15);
		
		
        frameNumber++;
        elapsedTimeMillis = Date.now() - startTime;
		
		/*if(elapsedTimeMillis >= 2000) {
			
			startTime = Date.now();
			draw();
			
			if(drawFrame) {
			
				//graphics.rect(x_coord*20, y_coord*20, 15, 15);
				//graphics.stroke();
				//x_coord += 10;
				//y_coord += 0;
				drawFrame = false;
				
			} else {
				draw();
				drawFrame = true;
			}
			
		
		} else {
			console.log("we ended up in else on line 208");
		}
		draw();*/

        requestAnimationFrame(doFrame);
    }
    

    function imageLoaded() {
		console.log("we loaded the image");
		allLoaded = true;
    }
	


	// this function gets called when HTML page loads
	// canvas context gets initialized
	// one sample image is loaded
	// keyboard handler initialized
	// game loop is setup
    function init() {
        try {
            canvas = document.getElementById("canvas");
            graphics = canvas.getContext("2d");
		
			
			
        } catch(e) {
            document.getElementById("canvasholder").innerHTML =
               "Canvas graphics is not supported.<br>" +
               "An error occurred while initializing graphics."
	    		+ e.message;
	          }

		image = new Image(15, 15);   // using optional size for image
		// load an image of intrinsic size 300x227 in CSS pixels
		image.src = 'https://openclipart.org/image/2400px/svg_to_png/243661/1457652300.png';
		image.onload = imageLoaded();
		while(!allLoaded) { console.log("loading image......"); } // very risky 
		
		
		
		
		graphics.fillStyle =  "#000000";
		graphics.fillRect(x_coord,y_coord, 15,15);
		

		// GAME INIT 
			food_x = parseInt(Math.random()*801);
			console.log("food x = " + food_x);
			food_y = parseInt(Math.random()*601);
			console.log("food y = " + food_y);
			
			//graphics.drawImage(image,food_x,food_y);
			graphics.fillStyle =  "#FF0000";
			graphics.fillRect(food_x,food_y, 15,15);
		
			
		
		
			
			
			console.log("food_x/30 " + food_x/30);
			console.log("food_y/40 " + food_y/40);

			grid[parseInt(food_x/30)][parseInt(food_y/40)] = "F";
			
			console.log("grid complete.");
			
			

		// handle keyboard
        document.addEventListener("keydown", doKeyDown, false);

        frameNumber = 0;
        elapsedTimeMillis = 0;
        startTime = Date.now();  // current time, in milliseconds.
        //draw();  // Call draw() to draw on the canvas.
        if (!window.requestAnimationFrame) { // This is for Internet Explorer 9
            window.requestAnimationFrame = function(callback) {
                setTimeout(callback, 1000/60);    
            }
        }
        requestAnimationFrame(doFrame);
    }
	
	
	
	
	
	function print_grid(grid) {
		res = "";
		for(var i = 0; i < grid.length; i++) {
			for(var j = 0; j < grid[0].length; j++) {
				if(j == grid[0].length-1) {
					res += grid[i][j] + "\n";
				} else {
					res += grid[i][j];
				}
			}
		}
		console.log(res);
	}
    