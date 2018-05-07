window.onload = function(){
	var canvas,
		context, 
		p0, 
		p1,
		isdown;

	(function() {
		canvas = document.getElementById("thecanvas");
		context = canvas.getContext("2d");

		var tranx = canvas.width * .5;
		var trany = canvas.height * .5;
		context.translate(tranx, trany);

		p0 = {x: 0, y: 0};
		p1 = {x: 0, y: 0};
		isdown = false;

		canvas.addEventListener('mousemove', function() {
			if(!isdown) {
				return;
			}

			p1.x = event.clientX - canvas.offsetLeft;
			p1.y = event.clientY - canvas.offsetTop;
			display();
		}, false);

		canvas.addEventListener('mousedown', function() {	
			isdown = true;
			p1.x = event.clientX - canvas.offsetLeft;
			p1.y = event.clientY - canvas.offsetTop;
			display();
		}, false);

		canvas.addEventListener('mouseup', function() {
			isdown = false;
			p1.x = event.clientX - canvas.offsetLeft;
			p1.y = event.clientY - canvas.offsetTop;
			display();
		}, false);

		display();
	})();

	function display() {
		context.clearRect(0, 0, canvas.width, canvas.height);
		var dx = p1.x - p0.x;
		var dy = p1.y - p0.y;

		context.fillStyle = "#000000";
		context.strokeStyle = "#000000";

		bresenham(p0, p1);
	}

	function setPixel(x, y) {
		context.fillRect(x, y, 1, 1);
	}

	function bresenham(p0, p1) {
		var rightward_x = p0.x < p1.x;
		var leftward_x = p0.x > p1.x;
		var upward_y = p0.y < p1.y;
		var downward_y = p0.y > p1.y;
		var no_y = p0.y == p1.y;
		
		var case1 = rightward_x && upward_y;
		var case2 = rightward_x && downward_y;
		var case3 = leftward_x && upward_y;
		var case4 = leftward_x && downward_y;
		var case5 = rightward_x && no_y;
		var case6 = leftward_x && no_y;
		
		var xstep, ystep;

		if(case1 || case2) {
			xstep = 1;
			ystep = case1 ? 1 : -1;
		}

		if(case3 || case4) {
			xstep = -1;
			ystep = case3 ? 1 : -1;
		}

		if(case5 || case6) {
			ystep = 0;
			xstep = case5 ? 1 : -1;
		}
		
		for(var x = p0.x; x <= p1.x; x += xstep) {
			var y = p0.y;
			var dx = p1.x = p0.x;
			var dy = p1.y = p0.y;
			var D = 2 * dy - dx;
			if(D > 0) {
				y += ystep;
			}
			setPixel(x,y);
		}
	}


	function mapcoords(oldx, oldy) {
		var oldleft, oldright, oldtop, oldbottom;
		oldleft = 0;
		oldright = canvas.width;
		oldtop = 0; 
		oldbottom = canvas.height;

		var newleft, newright, newtop, newbottom;
		newleft = canvas.width/-5.0;
		newright = canvas.width/5.0;
		newtop = canvas.height/5.0;
		newbottom = canvas.height/-5.0;

		var newx = newleft + ((oldx - oldleft) / (oldright - oldleft)) * (newright - newleft);
		var newy = newtop + ((oldy - oldtop) / (oldbottom - oldtop)) * (newbottom - newtop);

		var coords = {x: newx, y: newy};
		return coords;
	}
}
