/*
  GLだけをシングルトンで出せたら良いな
  多分今後　RenderやControl等に別れて Objも出来るんだろう
  programだけ保持しているけど設計考えよう。これは低レイヤーである
  低レイヤーだが、転送する値保持しておいて　同じなら送らないとか高速化考える9
 */


// global  シングルトンにしないと〜
ML.gl3d = {
	gl: null
};

ML.gl3d.raw = (function(){
"use strict"

	var gl_ = ML.gl3d.gl;

	function useProgram( program ){
		gl_.useProgram(program);
	}

	function init( _id ) {

		var id = _id || "canvas";
		var canvas = document.getElementById( id );

		gl_ = canvas.getContext("experimental-webgl") || canvas.getContext("webgl");
		if(!gl_) {
			document.write("This browser does not support webgl");ß
			return;
		}


	};


	function createBuffer( array, _target,  _usage ){
		var target = _target || gl_.ARRAY_BUFFER;
		var usage = _usage || gl_.STATIC_DRAW;
		var buf = gl_.createBuffer();
		gl_.bindBuffer(target, buf);
		gl_.bufferData(target, array, usage);

		return(buf);
	}

	function deleteBuffer( buf ){
		gl_.deleteBuffer(buf);
	}




	// shader
	function compileShaderVS( vss ){
		var vs = gl_.createShader(gl_.VERTEX_SHADER);
		gl_.shaderSource(vs, vss);
		gl_.compileShader(vs);
		if(!gl_.getShaderParameter(vs, gl_.COMPILE_STATUS)) {
			console.log("vertex shader compile error");
			console.log(gl_.getShaderInfoLog(vs));
			return;
		}

		return vs;
	}

	function compileShaderFS( fss ){
		var fs = gl_.createShader(gl_.FRAGMENT_SHADER);
		gl_.shaderSource(fs, fss);
		gl_.compileShader(fs);
		if(!gl_.getShaderParameter(fs, gl_.COMPILE_STATUS)) {
			console.log("fragment shader compile error");
			console.log(gl_.getShaderInfoLog(fs));
			return;
		}

		return fs;
	}

	function createProgram( vss, fss ){

		var vs = compileShaderVS(vss);
		var fs = compileShaderFS(fss);

		// Shaderをリンク
		var prog = gl_.createProgram();
		gl_.attachShader(prog, vs);
		gl_.attachShader(prog, fs);
		gl_.linkProgram(prog);
		if(!gl_.getProgramParameter(prog, gl_.LINK_STATUS)) {
			console.log("link error");
			console.log(gl_.getShaderInfoLog(fs));
			return;
		}

		return(prog);
	}



	function setVertexAttrib( field, buf, program ){
		// attributeのindex(position)を取得
		var pos = gl_.getAttribLocation(program, field );

		// 取得したattribute positionにバッファを送信
		gl_.bindBuffer(gl_.ARRAY_BUFFER, buf); // 頂点座標
		gl_.vertexAttribPointer(pos, 3, gl_.FLOAT, false, 0, 0); // float型を1頂点につき3つ、と指定
		gl_.enableVertexAttribArray(pos);
	}

	function uniformMatrix4fv( field, matrix, program ){
		gl_.uniformMatrix4fv(gl_.getUniformLocation(program, field), false, matrix);
	}


	function drawArrays( _mode ) {
		var mode = _mode || gl_.TRIANGLES;
		// 今まで設定した内容でWebGLに送信
		gl_.drawArrays( mode, 0, 3 );
	};


	function clear( _r, _g, _b, _a ){
		var r = _r || 0;
		var g = _g || 0;
		var b = _b || 0;
		var a = _a || 1;

		gl_.clearColor(r, g, b, a);
		gl_.clear(gl_.COLOR_BUFFER_BIT | gl_.DEPTH_BUFFER_BIT);
		gl_.enable(gl_.DEPTH_TEST);
	}



	return {
		gl: gl_,
        init: init,
        clear: clear,

		compileShaderVS:compileShaderVS,
		compileShaderFS:compileShaderFS,
        createProgram: createProgram,
        useProgram: useProgram,

        uniformMatrix4fv: uniformMatrix4fv,
        setVertexAttrib: setVertexAttrib,
        drawArrays: drawArrays,

        createBuffer:createBuffer,
        deleteBuffer: deleteBuffer,
      }


})();






