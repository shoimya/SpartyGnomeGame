FROM gitlab-runner:latest

RUN apt-get update -yq && \
    apt-get install -yq cmake gcc-11 g++-11 libwxgtk3.0-gtk3-dev
