#!/bin/bash

INPUT=${@?Missing class name}
CLASS_NAME=$(echo $INPUT | sed -r -e 's/\b([a-z])/\U\1/g' -e 's/\s+/_/g')
HUMAN_READABLE=${CLASS_NAME//_/ }
REPO=Qt-${CLASS_NAME//_/-}
COPY_YEARS=2013-$(date +%Y)
FILE_NAME=$(echo $CLASS_NAME | sed -r 's/([A-Z])/\L\1/g')
HEADER_GUARD=$(echo $CLASS_NAME | sed -r 's/([a-z])/\U\1/g')

REPLACE_VARS=(CLASS_NAME HUMAN_READABLE REPO COPY_YEARS FILE_NAME HEADER_GUARD)


SOURCE_DIR=$(dirname $(readlink -se "${BASH_SOURCE[0]}"))/template
TARGET_DIR=$(pwd)/$FILE_NAME


show_var=""
for var in ${REPLACE_VARS[@]}
do
	show_var="$show_var\n$var:=:${!var}:"
done
echo -e $show_var | column -t -c 3 -s ":"

function replace_sed()
{
	SED_OPTIONS=""
	for var in ${REPLACE_VARS[@]}
	do
		SED_OPTIONS="$SED_OPTIONS -e \"s/%$var%/${!var}/g\""
	done
	eval sed $SED_OPTIONS $@
}

function replace_string()
{
	echo $@ | replace_sed
}

function replace_dir()
{
	local SRC=${1?Missing source dir}
	local DEST=${2?Missing target dir}
	for file in $(ls -A $SRC)
	do
		local source_file=$SRC/$file
		local target_file=$DEST/$(replace_string $file)
		if [ -d $source_file ]
		then
			echo -e "\e[34;1m$source_file\n\t\e[36m$target_file\e[0m"
			mkdir -p $target_file
			replace_dir $source_file $target_file
		elif [ -f $source_file ]
		then
			echo -e "\e[33m$source_file\n\t\e[32m$target_file\e[0m" 
			replace_sed $source_file >$target_file
		fi
	done
}

mkdir -p $TARGET_DIR
replace_dir $SOURCE_DIR $TARGET_DIR

(cd $TARGET_DIR && git init && git remote add origin git@github.com:mbasaglia/$REPO.git && git add .)