#!/bin/sh
lessc --compress --source-map=css/style.map --source-map-rootpath=/profiles/commerce_kickstart/themes/bb_theme/ --source-map-basepath=`pwd` less/style.less > css/style.css
