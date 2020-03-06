#!/bin/bash

if [ -z $1 ]; then
    echo need atleast one param
    exit 1
fi

_DIR="$(cd "$(dirname "$0")" && pwd)"
_BASE_SO_DIR=${_DIR}/bicIdentify
_AMD_SO_DIR=${_BASE_SO_DIR}/amd64
_ARM__HUAWEI_SO_DIR=${_BASE_SO_DIR}/arm8_huawei
_TARGET_SO_DIR=${_BASE_SO_DIR}/linux
_AMD_GO_EXE=${_DIR}/minio_assistant_amd64
_ARM_HUAWEI_GO_EXE=${_DIR}/minio_assistant_arm8_huawei
_TARGET_GO_EXE=${_DIR}/minio_assistant

function rename_so_dir() {
    ARCH=$(uname -p)
    if [ "$ARCH" == "x86_64" ]; then
        echo "x86环境"
        mv -f ${_AMD_SO_DIR} ${_TARGET_SO_DIR}
        mv -f ${_AMD_GO_EXE} ${_TARGET_GO_EXE}
        echo "${_AMD_SO_DIR}  ${_AMD_GO_EXE}    ${_TARGET_SO_DIR}"
    elif [ "$ARCH" == "aarch64" ]; then
        OS=$(cat /proc/version | grep "Red Hat" | wc -l)
        if [ -z ${OS} ]; then
            # 飞腾环境
            echo "飞腾arm环境.暂不支持"
        else
            # 华为环境`
            echo "华为arm环境"
             mv -f ${_ARM__HUAWEI_SO_DIR} ${_TARGET_SO_DIR}
             mv -f ${_ARM_HUAWEI_GO_EXE} ${_TARGET_GO_EXE}
        fi

    else
        echo "暂不支持的CPU类型, [类型=${ARCH}]"
    fi

}

rename_so_dir

case "$1" in
    upload)
        echo "开始上传文件到minio"
        ${_TARGET_GO_EXE} -u
            ;;
    remove)
        echo "开始删除minio上的文件"
        ${_TARGET_GO_EXE} -r
    	   ;;
    *)
        echo "不支持的参数"
        exit 3
        ;;
esac