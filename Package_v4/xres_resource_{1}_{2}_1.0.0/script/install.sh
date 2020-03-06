#!/bin/sh
DIR="$( cd "$(dirname "$0")" && pwd )"
PIR=$(dirname "$DIR")
PPIR=$(dirname "$PIR")
MINIODIRNAME=minio_assistant_{2}
mv   ${PPIR}/bin/${MINIODIRNAME}  ${PPIR}/data
mv   ${PPIR}/bin/META-INF ${PPIR}/data/${MINIODIRNAME}
echo "start upload file to minio ${PPIR}"
chmod 777 -R    ${PPIR}/data
${PPIR}/data/${MINIODIRNAME}/upload_2_minio.sh upload