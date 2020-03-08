FROM gcc:latest

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

# This command compiles your app using GCC, adjust for your source code
RUN g++ -o lab2 lab2.cpp

# This command runs your application, comment out this line to compile only
CMD ["./lab2"]

LABEL Name=lab1 Version=0.0.1
