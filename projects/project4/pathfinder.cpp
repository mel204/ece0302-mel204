#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

typedef struct Coordinates
{
  int rows = 0;
  int cols = 0;
};

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  try
  {
    // Read input image from file
    Image<Pixel> image = readFromFile(input_file);
    Image<Pixel> imCopy = image;
    

    // TODO
    // variable to check theres only one starting point starting point
    bool validStart = 0;

    //get starting point
    Coordinates start;

    for (int i = 0; i < image.width(); i++)
    {
      for (int j = 0; j < image.height(); j++)
      {
        if(image(j, i) == RED)
        {
          validStart += 1;
          start.rows = j;
          start.cols = i;
        }
      }
    }

    if (!validStart)
    {
      std::cout << "more than one start" << std::endl;
      return EXIT_FAILURE;
    }

    //once start is established, begin BFS

    //queue to traverse image
    Queue<Coordinates, List<Coordinates>> frontier;
    //variable to exit while loop
    bool searching = true; 
    //initial coortinades 
    Coordinates curCoordinates = start;
    //surrounding coordinates
    Coordinates surCoordinates;
    //enqueue starting position
    frontier.enqueue(curCoordinates);
    //check if starting point is goal state
    if (curCoordinates.rows == ((image.height() - 1)||0) || curCoordinates.cols == ((image.width() - 1)||0))
    {
      imCopy(curCoordinates.rows, curCoordinates.cols) = BLUE;
      searching = false;
    }




    while(searching)
    {

      //if frontier is empty then there is no solution
      if (frontier.isEmpty())
      {
        searching = false;
      }

      //get next state
      //frontier.dequeue();

      //check left
      surCoordinates.cols = curCoordinates.cols - 1;
      surCoordinates.rows = curCoordinates.rows;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;

        if (surCoordinates.rows == ((image.height() - 1)||0) || surCoordinates.cols == ((image.width() - 1)||0))
          searching = false;
      }  


      //check right
      surCoordinates.cols = curCoordinates.cols + 1;
      surCoordinates.rows = curCoordinates.rows;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;

        if (surCoordinates.rows == ((image.height() - 1)||0) || surCoordinates.cols == ((image.width() - 1)||0))
          searching = false;
      } 
  

      //check down
      surCoordinates.rows = curCoordinates.rows + 1;
      surCoordinates.cols = curCoordinates.cols;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;

        if (surCoordinates.rows == ((image.height() - 1)||0) || surCoordinates.cols == ((image.width() - 1)||0))
          searching = false;
      } 
      
      //check up
      surCoordinates.rows = curCoordinates.rows - 1;
      surCoordinates.cols = curCoordinates.cols;
      if (imCopy(surCoordinates.rows, surCoordinates.cols) == WHITE)
      {
        frontier.enqueue(surCoordinates);
        imCopy(surCoordinates.rows, surCoordinates.cols) = BLUE;
        //move current coordinates
        curCoordinates = surCoordinates;

        if (surCoordinates.rows == ((image.height() - 1)||0) || surCoordinates.cols == ((image.width() - 1)||0))
          searching = false;
      } 

      searching = false;

    }

    //change solution path to green
    for (int i = 0; i < imCopy.width(); i++)
    {
      for (int j = 0; j < imCopy.height(); j++)
      {
        if(imCopy(j, i) == BLUE)
        {
          image(j, i) = GREEN;
        }
      }
    }
      

    // Write solution image to file

    writeToFile(image, output_file);

  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return EXIT_SUCCESS;

}
