"use strict";
var vertexShaderSource = 
	"attribute vec2 a_coords;\n" + 
	"attribute vec3 a_color;\n" + 
	"varying vec3 v_color;\n" + 
	"void main() {\n" + 
	"	gl_Position = vec4(a_coords, 0.0, 1.0);\n" + 
	"	v_color = a_color;\n" + 
	"}\n";
	
var fragmentShaderSource = 
	"precision mediump float;\n" + 
	"varying vec3 v_color;\n" +
	"void main() {\n" +
	"	gl_FragColor = vec4(v_color, 1.0);\n" +
	"}\n";
	
var gl,
	attributeCoords, 
	bufferCoords,
	attributeColor,
	bufferColor;

	
function draw() {
	gl.clearColor(0,0,0,1);
	gl.clear(gl.COLOR_BUFFER_BIT);
	var coords = new Float32Array([-0.9, -0.8, 0.9,-0.8, -0.9,0.9, 0.9,0.9]);
	gl.bindBuffer(gl.ARRAY_BUFFER, bufferCoords);
	gl.bufferData(gl.ARRAY_BUFFER, coords, gl.STREAM_DRAW);
	gl.vertexAttribPointer(attributeCoords, 2, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(attributeCoords);
	var color = new Float32Array([0,0,1,0,1,0,1,0,0,1,0,1]);
	gl.bindBuffer(gl.ARRAY_BUFFER, bufferColor);
	gl.bufferData(gl.ARRAY_BUFFER, color, gl.STREAM_DRAW);
	gl.vertexAttribPointer(attributeColor, 3, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(attributeColor);
	var elementBuffer = gl.createBuffer();
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, elementBuffer);
	var data = new Uint8Array([0,1,2,1,2,3]);
	gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, data, gl.STREAM_DRAW);
	gl.drawElements(gl.TRIANGLES, 6, gl.UNSIGNED_BYTE, 0);
}

function createProgram(gl, vertexShaderSource, fragmentShaderSource) {
	var vsh = gl.createShader(gl.VERTEX_SHADER);
	gl.shaderSource(vsh, vertexShaderSource);
	gl.compileShader(vsh);
	if(!gl.getShaderParameter(vsh, gl.COMPILE_STATUS)) {
		console.log("Error in vertex shader:  " + gl.getShaderInfoLog(vsh));
		throw "Error in vertex shader: " + gl.getShaderInfoLog(vsh);
	}
	var fsh = gl.createShader(gl.FRAGMENT_SHADER);
	gl.shaderSource(fsh, fragmentShaderSource);
	gl.compileShader(fsh);
	if(!gl.getShaderParameter(fsh, gl.COMPILE_STATUS)) {
		console.log("Error in fragment shader: " + gl.getShaderInfoLog(fsh));
		throw "Error in fragment shader: " + gl.getShaderInfoLog(fsh);
	}
	var prog = gl.createProgram();
	gl.attachShader(prog, vsh);
	gl.attachShader(prog, fsh);
	gl.linkProgram(prog);
	if(!gl.getProgramParameter(prog, gl.LINK_STATUS)) {
		console.log("Link error in program: " + gl.getProgramInfoLog(prog));
		throw "Link error in program: " + gl.getProgramInfoLog(prog);
	}
	return prog;
}

function initGL() {
	var prog = createProgram(gl, vertexShaderSource, fragmentShaderSource);
	gl.useProgram(prog);
	attributeCoords = gl.getAttribLocation(prog, "a_coords");
	bufferCoords = gl.createBuffer();
	attributeColor = gl.getAttribLocation(prog, "a_color");
	bufferColor = gl.createBuffer();
}

window.onload = function init() {
	try {
		var canvas = document.getElementById("webglcanvas");
		var options = {
			alpha: false,
			depth: false
		};
		gl = canvas.getContext("webgl", options) || 
			canvas.getContext("experimental-webgl", options);
		if(!gl) {
			console.log("Browser does not support WebGL");
			throw "Browser does not support WebGL";
		}
		
	} catch(e) {
		console.log("could not get a web gl graphics context");
	}
	
	try {
		initGL();
	} catch(e) {
		console.log("could not get a web gl graphics context");
	}
	draw();
}
