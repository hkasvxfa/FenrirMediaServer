@echo off
set path=C:\Program Files\NASM;%path%
C:
set OPENSSL_VERSION=3.0.0
set SEVENZIP="C:\Program Files\7-Zip-Zstandard\7z.exe"
set VS2019_AMD64="C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvars64.bat"


IF NOT EXIST "C:\openssl-src-win64" GOTO NO_WIN64_SOURCE
DEL "C:\openssl-src-win64" /Q /F /S
RMDIR /S /Q "C:\openssl-src-win64"
:NO_WIN64_SOURCE

del openssl-%OPENSSL_VERSION%.tar
%SEVENZIP% e openssl-%OPENSSL_VERSION%.tar.gz
%SEVENZIP% x -y openssl-%OPENSSL_VERSION%.tar
ren openssl-%OPENSSL_VERSION% openssl-src-win64-VS2019
DEL pax_global_header


CALL %VS2019_AMD64%

C:

cd \openssl-src-win64-VS2019
perl Configure VC-WIN64A no-shared no-weak-ssl-ciphers --prefix=C:\openssl-%OPENSSL_VERSION%-64bit-release-static-VS2019 -D_WIN32_WINNT=0x0600
nmake -f Makefile install

cd ../

%SEVENZIP% a -r openssl-%OPENSSL_VERSION%-64bit-release-static-VS2019.7z openssl-%OPENSSL_VERSION%-64bit-release-static-VS2019\*

DEL openssl-%OPENSSL_VERSION%-64bit-release-static-VS2019 /Q /F /S

RMDIR /S /Q openssl-%OPENSSL_VERSION%-64bit-release-static-VS2019
RMDIR /S /Q openssl-src-win64-VS2019
del openssl-%OPENSSL_VERSION%.tar
pause