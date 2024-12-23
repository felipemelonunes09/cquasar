FROM gcc:latest

# Install make 
RUN apt-get update && apt-get install -y make

# Set the working directory in the container
WORKDIR /usr/src/app

COPY . .

# Run make to build the project
RUN make

