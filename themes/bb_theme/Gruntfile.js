module.exports = function(grunt) {
  grunt.initConfig({
    less: {
      development : {
        options : {
          compress: true,
          paths: ['less'],
          sourceMap: true,
          sourceMapFilename: 'css/style.map', // where file is generated and located
          sourceMapBasepath: '/profiles/commerce_kickstart/themes/bb_theme/', // Sets sourcemap base path, defaults to current working directory.
        },
        files :{
          'css/style.css' : 'less/style.less',
        },
      }
    },
    watch : {
      styles : {
        files : ['less/*.less'],
        tasks : ['less'],
      },
      options : {
        livereload : true
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-less');
  grunt.loadNpmTasks('grunt-contrib-watch');

  grunt.registerTask('default', ['watch']);
}
