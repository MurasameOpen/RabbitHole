var require = {
    paths: {
        'underscore': '../lib/underscore-1.8.3.min',
        'jquery': '../lib/jquery-2.1.4.min',
        'game_main': '../js/game_main',
        'ML': '../js/ML',
        'MLTouch': '../js/MLTouch'
    },

     shim: {

        'ML': {
            depends:['jquery'],
            exports: 'ML'
        },

        'MLTouch': {
            depends:['ML'],
            exports: 'ML.Touch'
        }
     }
};