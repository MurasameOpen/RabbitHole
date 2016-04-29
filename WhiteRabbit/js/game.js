/*
 インスタンス化しない
 */




var GM = (function () {
"use strict";


const Dir = {
  center: 0,
  left: 1,
  right: 2,
  up: 3,
  down: 4,
}
// private:
  var x_ = 0;
  var y_ = 0;
  var toX_ = 0;
  var toY_ = 0;
  var spd = 0.1;

  var dir_ = Dir.left;

  var canvasSizeX_ = 272;
  var canvasSizeY_ = 208;

  var screenRateX_ = 1.0;
  var screenRateY_ = 1.0;


  var vertex_;
  var normal_;

  var program_;

  var GL = ML.gl3d.raw;

// public:
    function init ( callback ) {

        //　本当は Resizeのたびに呼ぶ必要があるが・・
        screenRateX_ = canvasSizeX_ / window.parent.screen.width;
        screenRateY_ = canvasSizeY_ / window.parent.screen.height;

        ML.touch.init(screenRateX_,screenRateY_);


        // set 3d
        GL.init("canvas");
        program_ = GL.createProgram($("#vs")[0].text, $("#fs")[0].text);
//        program_ = GL.createProgram(document.getElementById("vs").text, document.getElementById("fs").text);
//        if(program_) GL.setProgram(program_);
        if(program_) GL.useProgram(program_);

        vertex_ = GL.createBuffer( new Float32Array([-0.5, -0.5, 0, 0.5, -0.5, 0, 0.5, 0.5, 0]) );
        normal_ = GL.createBuffer( new Float32Array([0, 0, 1, 0, 0, 1, 0, 0, 1]) );

        callback();

         setInterval(main, 15);
    }

var frame=0;

    function main() {
      GL.clear();
      ML.touch.poll();





		frame++;
		// frustum行列の生成
		var proj_mat = mat4.create();
		mat4.frustum(proj_mat, -1, 1, -1, 1, 3, 10);
		// 移動回転行列の生成
		var mv_mat = mat4.create();
		mat4.translate(mv_mat, mv_mat, [0, 0, -6]);
		mat4.rotate(mv_mat, mv_mat, frame * 0.01, [0, 1, 0]); // 軸[0, 1, 0]で回転




      // uniform
	  GL.uniformMatrix4fv("projectionMatrix", proj_mat, program_ );
	  GL.uniformMatrix4fv("modelviewMatrix", mv_mat, program_ );

      // vertex
      GL.setVertexAttrib( "vertex", vertex_, program_ );
      GL.setVertexAttrib( "normal", normal_, program_ );

      GL.drawArrays( );

    }




  function lerp( x, Y, f ){
    return X * ( 1.0 - f ) + Y * f;
  }

  function clamp(x, min, max){
    if( x < min ){
      x = min;
    }else if(x > max){
      x = max;
    }

    return(x);
  }




return {

    init: init,
    main: main,
//    canvasSizeX_: this.canvasSizeX_,

  }

})();



