/*
 * Copyright  rocedu@BESTI   rocedu@qq.com   All rights reserved.
 *
 * 文件创建程序，接受一个命令行参数作为文件名并创建该文件。
 * 如果参数不正确或文件创建失败，程序将打印错误信息。
 */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {
    int errornum;  // 变量用于存储错误代码
    char filename[PATH_MAX] = {0};  // 用于存储文件名的字符数组，初始化为0

    // 检查命令行参数数量是否正确
    if (argc != 2) {
        fprintf(stderr, "You must supply a filename as an argument \n");
        return 1;  // 返回1表示错误
    }

    // 安全地拷贝命令行提供的文件名到filename数组
    strncpy(filename, argv[1], sizeof(filename) - 1);
    // 确保最后一个字符为'\0'以避免字符串未终止
    filename[sizeof(filename) - 1] = '\0';

    // 创建文件并设置权限为0644
    if (creat(filename, 00644) == -1) {
        errornum = errno;  // 保存errno的值
        fprintf(stderr, "Can't create file %s \n", filename);  // 打印文件创建错误信息
        fprintf(stderr, "%s \n", strerror(errornum));  // 打印具体的错误原因
        return 1;  // 返回1表示错误
    }

    return 0;  // 返回0表示成功
}

