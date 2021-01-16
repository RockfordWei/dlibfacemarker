FROM swift:5.3
ENV CMK_VER 3.19.3
ENV CMK_SHL cmake-${CMK_VER}-Linux-x86_64.sh
RUN apt-get update -y && apt-get install -y wget libx11-dev libopenblas-dev
RUN cd /tmp && wget https://github.com/Kitware/CMake/releases/download/v${CMK_VER}/${CMK_SHL}
RUN chmod +x /tmp/${CMK_SHL} && /tmp/${CMK_SHL} --prefix=/usr/local/ --skip-license
