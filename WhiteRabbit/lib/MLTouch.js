
ML.touch = (function(){
"use strict";

// private:
  var screenRateX_ = 1.0;
  var screenRateY_ = 1.0;

  var downX_ = new Array();
  var downY_ = new Array();

  var touch_;

  var TouchState = function(){
    this.on = false;
    this.x_ =   0;
    this.y_ = 0;
  }

  // マルチタッチ2個までにおさえる・・
  const MULTITOUCH_COUNT = 2;
  const HISTORY_COUNT = 15;



// public:
    function init ( ratex, ratey ) {

      var screenRateX_ = ratex
      var screenRateY_ = ratey;


      touch_ = new Array();
      for(var i=0; i< HISTORY_COUNT; i++ ){
          touch_[i] = new Array();
        for(var j=0; j< MULTITOUCH_COUNT; j++ ){
          touch_[i][j] = new TouchState();
        }
      }

        $(window).bind('mousedown', function() {
          event.preventDefault();     // ページの反応を止める（A タグや画像の反応など）
          touch_[0][0].on = true;
          downX_[0] = event.pageX * screenRateX_;
          downY_[0] = event.pageY * screenRateY_;
          touch_[0][0].x_ = downX_;
          touch_[0][0].y_ = downY_;
        });


        $(window).bind('touchstart', function() {
            event.preventDefault();                     // ページが動いたり、反応を止める（A タグなど）
            for(var i=0; i<MULTITOUCH_COUNT; i++ ){
              if( !event.changedTouches[i] ) break;
              touch_[0][i].on = true;
              touch_[0][i].x = event.changedTouches[i].pageX;
              touch_[0][i].y = event.changedTouches[i].pageY;
            }
        });

        $(window).bind('mouseup', function() {
          touch_[0][0].on = false;
          touch_[0][0].x_ = event.pageX * screenRateX_;
          touch_[0][0].y_ = event.pageY * screenRateY_;
//          alert("up");
        });

        $(window).bind('touchend', function() {
            for(var i=0; i<MULTITOUCH_COUNT; i++ ){
              if( !event.changedTouches[i] ) break;
              touch_[0][i].on = false;
              // eventからとれない
//              touch_[0][i].x = event.changedTouches[i].pageX;
//              touch_[0][i].y = event.changedTouches[i].pageY;
              touch_[0][i].x = touch_[1][i].x;
              touch_[0][i].y = touch_[1][i].y;
            }
        });


        $(window).bind('mousemove', function() {
            event.preventDefault();                     // ページが動いたり、反応を止める（A タグなど）
//          touch_[1][0].on = true;
          touch_[0][0].x_ = event.pageX * screenRateX_;
          touch_[0][0].y_ = event.pageY * screenRateY_;
        });

        $(window).bind('touchmove', function() {
            event.preventDefault();                     // ページが動いたり、反応を止める（A タグなど）
            for(var i=0; i<MULTITOUCH_COUNT; i++ ){
              if( !event.changedTouches[i] ) break;
//              touch_[0][i].x = event.changedTouches[i].pageX;
//              touch_[0][i].y = event.changedTouches[i].pageY;
            }
        });
    }
    // フレームに１回呼ぶ
    function poll() {

        for(var i=HISTORY_COUNT-1; i>0; i--){
            for(var j=0; j<MULTITOUCH_COUNT; j++){
                touch_[i][j].on = touch_[i-1][j].on;
                touch_[i][j].x_ = touch_[i-1][j].x_;
                touch_[i][j].y_ = touch_[i-1][j].y_;
            }
        }

//        touch_.unshift( touch_[0] );
//        touch_.pop();

  //       if( touch_[5][0].on != touch_[6][0].on) alert("on");


        // キーイベント割り込んだら終わる
        for(var j=0; j< MULTITOUCH_COUNT; j++ ){
          touch_[0][j].on = touch_[1][j].on;
          touch_[0][j].x_ = touch_[1][j].x_;
          touch_[0][j].y_ = touch_[1][j].y_;
        }


        var s="";
        for(var i=0; i<HISTORY_COUNT; i++){
            if(touch_[i][0].on){
                s+= "o "
            }else{
                s+= "x "
            }
        }



    }

    function down(_multi) {
      var multi = _multi || 0;

      if(touch_[1][multi].on && (!touch_[2][multi].on) ){
        return(touch_[1][multi]);
      }else{
        return(null);
      }
    }

    function up(_multi) {
      var multi = _multi || 0;

      if( (!touch_[1][multi].on) && touch_[2][multi].on){
        return(touch_[1][multi]);
      }else{
        return(null);
      }
    }

    function move(_multi) {
      var multi = _multi || 0;

      if( touch_[1][multi].on && touch_[2][multi].on ){
        return(touch_[1][multi]);
      }else{
        return(null);
      }
    }

    function flick( _multi  ) {
      var multi = _multi || 0;

      if( !touch_[1][multi].on && touch_[2][multi].on ){
        return( {x_:touch_[1][multi].x_ - downX_[multi], y_:touch_[1][multi].y_ - downY_[multi] } );
      }else{
        return(null);
      }
    }




return {
    init: init,
    poll: poll,
    down: down,
    up: up,
    move: move,
    flick: flick,


  }


}());
