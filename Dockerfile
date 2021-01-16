FROM swift:5.3
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get -y update && apt-get install -y openssl libssl-dev libpq-dev uuid-dev
RUN apt-get install -y curl build-essential cmake libgtk-3-dev libboost-all-dev ffmpeg
RUN apt-get install -y git libx11-dev libopenblas-dev liblapack-dev