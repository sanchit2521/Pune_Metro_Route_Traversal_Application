#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>


#define V 91
#define MAX 91

int predecessor[100];
int reverse_path[100];
int correct_path[100];
char *color[100];
int stack[50];
int top = -1;
int stacksize = 100;
float adj[MAX][MAX];
float dist[MAX];


void push(int data)
{
    if (top == stacksize - 1)
    {
        printf("Stack Overflow\n");
        // exit(1);
    }
    top = top + 1;
    stack[top] = data;
    return;
}

int pop()
{
    int data;
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    data = stack[top];
    top = top - 1;
    return data;
}
void display_time(int src, int station1, int station2)
{
    time_t t = time(NULL);
    struct tm Time = *localtime(&t);
    if (Time.tm_hour >= 8 && Time.tm_hour <= 22)
    {
        if (station1 - station2 == -1)
        {
            if (src == 0 || src == 20 || src == 49 || src == 69)
            {
                if (Time.tm_min == 0)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 00);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 00);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 00);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 00);
                    }
                }
            }

            else if ((src >= 1 && src <= 4) || (src >= 21 && src <= 25) || (src >= 50 && src <= 52) || (src >= 70 && src <= 73))
            {
                if (Time.tm_min <= 5)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 05);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 05);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 05);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 05);
                    }
                }
            }
            else if ((src >= 5 && src <= 8) || (src >= 26 && src <= 31) || (src >= 53 && src <= 56) || (src >= 74 && src <= 77))
            {
                if (Time.tm_min <= 10)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 10);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 10);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 10);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 10);
                    }
                }
            }
            else if ((src >= 9 && src <= 11) || (src >= 32 && src <= 37) || (src >= 57 && src <= 60) || (src >= 78 && src <= 81))
            {
                if (Time.tm_min <= 15)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 15);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 15);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 15);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 15);
                    }
                }
            }
            else if ((src >= 12 && src <= 15) || (src >= 38 && src <= 42) || (src >= 61 && src <= 64) || (src >= 82 && src <= 85))
            {
                if (Time.tm_min <= 20)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 20);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 20);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 20);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 20);
                    }
                }
            }
            else if ((src >= 16 && src <= 18) || (src >= 43 && src <= 47) || (src >= 65 && src <= 67) || (src >= 86 && src <= 89))
            {
                if (Time.tm_min <= 25)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 25);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 25);
                    }
                }
            }
        }

        else if (station1 - station2 == 1)
        {
            if (src == 19 || src == 48 || src == 68 || src == 90)
            {
                if (Time.tm_min == 30)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 30);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 30);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 30);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 30);
                    }
                }
            }
            else if ((src >= 1 && src <= 4) || (src >= 21 && src <= 25) || (src >= 50 && src <= 52) || (src >= 70 && src <= 73))
            {
                if (Time.tm_min <= 25)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 25);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 25);
                    }
                }
            }
            else if ((src >= 5 && src <= 8) || (src >= 26 && src <= 31) || (src >= 53 && src <= 56) || (src >= 74 && src <= 77))
            {
                if (Time.tm_min <= 20)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 25);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 25);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 25);
                    }
                }
            }
            else if ((src >= 9 && src <= 11) || (src >= 32 && src <= 37) || (src >= 57 && src <= 60) || (src >= 78 && src <= 81))
            {
                if (Time.tm_min <= 15)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 15);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 15);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 15);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 15);
                    }
                }
            }
            else if ((src >= 12 && src <= 15) || (src >= 38 && src <= 42) || (src >= 61 && src <= 64) || (src >= 82 && src <= 85))
            {
                if (Time.tm_min <= 10)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 10);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 10);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 10);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 10);
                    }
                }
            }
            else if ((src >= 16 && src <= 18) || (src >= 43 && src <= 47) || (src >= 65 && src <= 67) || (src >= 86 && src <= 89))
            {
                if (Time.tm_min <= 5)
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour % 12 == 0) ? 12 : Time.tm_hour % 12, 05);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", Time.tm_hour, 05);
                    }
                }
                else
                {
                    if (Time.tm_hour >= 12) {
                        printf("The Metro is scheduled to arrive at %2d:%02d PM\n", (Time.tm_hour + 1) % 12, 05);
                    } else {
                        printf("The Metro is scheduled to arrive at %2d:%02d AM\n", (Time.tm_hour + 1) % 12, 05);
                    }
                }
            }
        }
    }
    else
    {
        printf("Metro isnot available now\n");
    }
}


void Give_color_to_station()
{
    for (int i = 0; i <= 19; i++)
    {
        color[i] = "Purple";
    }

    for (int i = 20; i <= 48; i++)
    {
        color[i] = "Aqua";
    }

    for (int i = 49; i <= 68; i++)
    {
        color[i] = "Yellow";
    }

    for (int i = 69; i <= 90; i++)
    {
        color[i] = "Green";
    }
}

int Min_Distance_Node(float dist[V], bool visited[V])
{
    int min = INT_MAX;
    int min_node;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void numToName(int t)

{
    switch (t)
    {

    // Purple Line
    case 0:
        printf("PCMC->\n");
        break;
    case 1:
        printf("Sant Tukaram Nagar->\n");
        break;
    case 2:
        printf("Bhosari/Nashik Phata->\n");
        break;
    case 3:
        printf("Kasarwadi->\n");
        break;
    case 4:
        printf("Phugewadi->\n");
        break;
    case 5:
        printf("Dapodi->\n");
        break;
    case 6:
        printf("Bopodi->\n");
        break;
    case 7:
        printf("Khadaki->\n");
        break;
    case 8:
        printf("Range Hill->\n");
        break;
    case 9:
        printf("Shivaji Nagar->\n");
        break;
    case 10:
        printf("Budhwar Peth->\n");
        break;
    case 11:
        printf("Mandai->\n");
        break;
    case 12:
        printf("Swargate->\n");
        break;
    case 13:
        printf("Laxmi Narayan Talkies->\n");
        break;
    case 14:
        printf("Bhapkar Petrol Pump->\n");
        break;
    case 15:
        printf("Padmavati->\n");
        break;
    case 16:
        printf("Balaji Nagar->\n");
        break;
    case 17:
        printf("Bharti Vidyapeeth gate->\n");
        break;
    case 18:
        printf("Sarpodyan->\n");
        break;
    case 19:
        printf("Katraj->\n");
        break;

    // Aqua line
    case 20:
        printf("Chandani Chowk->\n");

        break;
    case 21:
        printf("Vanaz->\n");
        break;

    case 22:
        printf("Anand Nagar->\n");
        break;
    case 23:
        printf("Ideal colony->\n");
        break;
    case 24:
        printf("Nal Stop->\n");
        break;
    case 25:
        printf("Garware College->\n");
        break;
    case 26:
        printf("Deccan Gymkhana->\n");
        break;
    case 27:
        printf("Chhatrapati Sambhaji Udyan->\n");
        break;
    case 28:
        printf("PMC->\n");
        break;
    case 29:
        printf("Civil Court->\n");
        break;
    case 30:
        printf("Mangalwar Peth->\n");
        break;
    case 31:
        printf("Pune Railway Station->\n");
        break;
    case 32:
        printf("Ruby Hall Clinic->\n");
        break;
    case 33:
        printf("Bund Garden->\n");
        break;
    case 34:
        printf("Yerawada->\n");
        break;
    case 35:
        printf("Kalayani Nagar->\n");
        break;
    case 36:
        printf("Ramwadi->\n");
        break;

    case 37:
        printf("Wadgaon Sheri Phata->\n");
        break;

    case 38:
        printf("Viman Nagar Corner->\n");
        break;
    case 39:
        printf("Tata Guardroom->\n");
        break;
    case 40:
        printf("Kharadi Bypass->\n");
        break;
    case 41:
        printf("Janak Baba Dargha->\n");
        break;
    case 42:
        printf("Aaple Ghar->\n");
        break;
    case 43:
        printf("Khandve Nagar->\n");
        break;
    case 44:
        printf("Ubale Nagar->\n");
        break;
    case 45:
        printf("Godown Talera->\n");
        break;
    case 46:
        printf("Soyrik Mangal Karyalay->\n");
        break;
    case 47:
        printf("Kamal Bagh->\n");
        break;
    case 48:
        printf("Wagholi->\n");
        break;

    // Yellow line
    case 49:
        printf("Metropolic Circle->\n");
        break;
    case 50:
        printf("Embassy quadron business park->\n");
        break;
    case 51:
        printf("Dohler->\n");
        break;
    case 52:
        printf("Infosys Phase 2->\n");
        break;
    case 53:
        printf("Pall India->\n");
        break;
    case 54:
        printf("Shivaji Chowk->\n");
        break;
    case 55:
        printf("Hinjewadi->\n");
        break;
    case 56:
        printf("Wakad Chowk->\n");
        break;
    case 57:
        printf("Balewadi Stadium->\n");
        break;
    case 58:
        printf("NICMAR->\n");
        break;
    case 59:
        printf("Ram Nagar->\n");
        break;
    case 60:
        printf("Laxmi Nagar->\n");
        break;
    case 61:
        printf("Balewadi Phata->\n");
        break;
    case 62:
        printf("Banergaon->\n");
        break;
    case 63:
        printf("Baner->\n");
        break;
    case 64:
        printf("Krushi Anusadhan->\n");
        break;
    case 65:
        printf("Sakal Nagar->\n");
        break;
    case 66:
        printf("University->\n");
        break;
    case 67:
        printf("RBI->\n");

        break;
    case 68:
        printf("Agriculture College->\n");
        break;

    // Green line
    case 69:
        printf("Kharadi Chowk->\n");
        break;
    case 70:
        printf("Colombia Asia Hospital->\n");
        break;
    case 71:
        printf("Mundhawa Chowk->\n");
        break;

    case 72:
        printf("Spring Valley Apartment->\n");
        break;

    case 73:
        printf("Magarpatta Manapa Shala->\n");
        break;
    case 74:
        printf("Tilekar Vaoti->\n");
        break;
    case 75:
        printf("Hadapsar MIDC->\n");
        break;
    case 76:
        printf("Fatima Nagar->\n");
        break;
    case 77:
        printf("Race Course/AFMC->\n");
        break;
    case 78:
        printf("Golibar Maidan->\n");
        break;
    case 79:
        printf("Saras Baug->\n");
        break;
    case 80:
        printf("Dandekar Pool->\n");
        break;
    case 81:
        printf("Ganesh Mala->\n");
        break;
    case 82:
        printf("Rajaram Pul->\n");
        break;
    case 83:
        printf("Manik Baug->\n");
        break;

    case 84:
        printf("Vadagaon Khurd Phata->\n");
        break;
    case 85:
        printf("Patil Colony->\n");
        break;
    case 86:
        printf("Dhayari Phata->\n");
        break;
    case 87:
        printf("Lagadmala->\n");
        break;
    case 88:
        printf("Mate Pat->\n");
        break;
    case 89:
        printf("Nanded City->\n");
        break;

    case 90:
        printf("Khadakwasala->\n");
        break;
        return;
    }
}


void dijkstra(int src, int destinationNumber)
{
    int min = INT_MAX;

    bool visited[V];
    
    for (int i = 0; i < V; i++)
    {
        predecessor[i] = 0;
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int j = 0; j < V; j++)
    {
        int min_node = Min_Distance_Node(dist, visited);
        visited[min_node] = true;

        for (int k = 0; k < V; k++)
        {
            if (!visited[k] && dist[min_node] != INT_MAX && adj[min_node][k] && dist[min_node] + adj[min_node][k] < dist[k])
            {
                predecessor[k] = min_node;
                dist[k] = dist[min_node] + adj[min_node][k];
            }
        }
    }
}

void solve_conflict(int i)
{
    // if junction is swargate
    if (correct_path[i] == 12)
    {
        if (color[correct_path[i - 1]] != color[correct_path[i + 1]])
        {

            if (correct_path[i + 1] == 78 && color[correct_path[i - 1]] == "Purple" && color[correct_path[i + 1]] == "Green")
            {
                
                printf("\nYou have to change the route and board on a metro heading towards Kharadi\n");
            }

            else if (correct_path[i + 1] == 79 && color[correct_path[i - 1]] == "Purple" && color[correct_path[i + 1]] == "Green")
            {
                
                printf("\nYou have to change the route and board on a metro heading towards Khadakwasala Dam\n");
            }

            else if (correct_path[i + 1] == 11 && color[correct_path[i - 1]] == "Green" && color[correct_path[i + 1]] == "Purple")
            {
                
                printf("\nYou have to change the route and board on a metro heading towards PCMC\n");
            }

            else if (correct_path[i + 1] == 13 && color[correct_path[i - 1]] == "Green" && color[correct_path[i + 1]] == "Purple")
            {
              
                printf("\nYou have to change the route and board on a metro heading towards Katraj\n");
            }
        }
    }

    //if junction is shivajinagar
    else if (correct_path[i] == 9)
    {
        if (color[correct_path[i - 1]] != color[correct_path[i + 1]])
        {

            if (color[correct_path[i - 1]] == "Purple" && color[correct_path[i + 1]] == "Yellow")
            {
               
                printf("\nYou have to change the route and board on a metro heading towards Hinjewadi\n");
            }

            if (correct_path[i + 1] == 8 && color[correct_path[i - 1]] == "Yellow" && color[correct_path[i + 1]] == "Purple")
            {
                
                printf("\nYou have to change the route and board on a metro heading towards PCMC\n");
            }

            if (color[correct_path[i - 1]] == "Purple" && color[correct_path[i + 1]] == "Aqua" && correct_path[i + 1] == 28)
            {
                
                printf("\nYou have to change the route and board on a metro heading towards Chandani Chowk\n");
            }


        }
    }

    // if junction is Civil Court
    else if (correct_path[i] == 29)

    {

        if (correct_path[i + 1] == 10 && color[correct_path[i - 1]] == "Aqua" && color[correct_path[i + 1]] == "Purple")
        {
            
            printf("\nYou have to change the route and board on a metro heading towards Katraj\n");
        }

        

        else if (correct_path[i + 2] == 8 && color[correct_path[i - 1]] == "Aqua" && color[correct_path[i + 2]] == "Purple")
        {
            
            printf("\nYou have to change the route and  board on a metro heading towards PCMC\n");
        }

        else if (correct_path[i + 2] == 68 && color[correct_path[i - 1]] == "Aqua" && color[correct_path[i + 2]] == "Yellow")
        {
            
            printf("\nYou have to change the route and  board on a metro heading towards  Hinjewadi\n");
        }

        else if (color[correct_path[i - 1]] == "Purple" && correct_path[i + 1] == 28 && color[correct_path[i + 1]] == "Aqua")
        {
            
            printf("\nYou have to change the routeand  board on a metro heading towards  Chandani Chowk\n");
        }

        else if (color[correct_path[i - 1]] == "Purple" && correct_path[i + 1] == 30 && color[correct_path[i + 1]] == "Aqua")
        {

            printf("\nYou have to change the route and  board on a metro heading towards  Wagholi\n");
        }

        else if (color[correct_path[i - 1]] != "Purple" && (correct_path[i + 4] == 78 || correct_path[i + 4] == 79))
        {
            printf("\nYou have to change the route and board on metro heading towards Katraj\n");
        }

        else if (color[correct_path[i + 2]] == "Yellow")
        {
            printf("\nYou have to change the route and board on metro heading towards Hinjewadi\n");
        }
    }
}


void right_direction(int sourcenumber, int current_source, int next_to_current_source)
{
    if (current_source - next_to_current_source == -67)
    {
        printf("Board on a metro heading towards Khadakwasala\n\n");
    }
    else if (current_source - next_to_current_source == 20)
    {
        printf("Board on a metro heading towards PCMC \n\n");
    }

    else if (current_source - next_to_current_source == 19)
    {
        printf("Board on a metro heading towards Katraj\n\n");
    }
    else if (color[sourcenumber] == "Purple")
    {
        printf("Board on a metro heading towards Katraj\n\n");
    }
    else if (color[sourcenumber] == "Aqua")
    {
        printf("Board on a metro heading towards Wagholi\n\n");
    }
    else if (color[sourcenumber] == "Yellow")
    {
        printf("Board on a metro heading towards Civil Court\n\n");
    }
    else if (color[sourcenumber] == "Green")
    {
        printf("Board on a metro heading towards Khadakwasala\n\n");
    }
}

void left_direction(int sourcenumber, int current_source, int next_to_current_source)
{
    if (current_source - next_to_current_source == -20)
    {
        printf("Board on a metro heading towards Katraj\n\n");
    }

    else if (current_source - next_to_current_source == -66)
    {
        printf("Board on a metro heading towards Kharadi\n\n");
    }
    else if (color[sourcenumber] == "Purple")
    {
        printf("Board on a metro heading towards PCMC\n\n");
    }
    else if (color[sourcenumber] == "Aqua")
    {
        printf("Board on a metro heading towards Chandani Chowk\n\n");
    }
    else if (color[sourcenumber] == "Yellow")
    {
        printf("Board on a metro heading towards Hinjewadi\n\n");
    }
    else if (color[sourcenumber] == "Green")
    {
        printf("Board on a metro heading towards Kharadi\n\n");
    }
}

void findPath(int sourcenumber, int destinationnumber, char *sourcecolor)
{
    int count = 0;
    while (destinationnumber != sourcenumber)
    {

        reverse_path[count] = destinationnumber;
        int u = predecessor[destinationnumber];
        destinationnumber = u;
        count++;
    }

    reverse_path[count] = sourcenumber;
    count++;

    for (int j = 0, i = count; j <= count, i >= 0; j++, i--)
    {
        correct_path[j] = reverse_path[i];
    }

    int current_source = correct_path[1];
    int next_to_current_source = correct_path[2];

    display_time(sourcenumber,current_source,next_to_current_source);

   
    if (current_source - next_to_current_source == -1 || current_source - next_to_current_source == 20 || current_source - next_to_current_source == -67 || current_source - next_to_current_source == 19)
    {

        right_direction(sourcenumber, current_source, next_to_current_source);
    }

    if (current_source - next_to_current_source == 1 || current_source - next_to_current_source == -20 || current_source - next_to_current_source == -66)
    {
        left_direction(sourcenumber, current_source, next_to_current_source);
    }

    
    for (int i = 1; i <= count; i++)
    {

        if (correct_path[i] == 9 || correct_path[i] == 12 || correct_path[i] == 29)
        {   
            solve_conflict(i);
            numToName(correct_path[i]);
        }

        else if (color[correct_path[i]] == color[correct_path[i + 1]])
        {
            numToName(correct_path[i]);
        }
    }
}

int Check_Station(char *a, char *b)
{
   
    int n1 = strlen(a);
    int n2 = strlen(b);
    
    int count = 0;
    int j;

    
    for (int i = 0; i < n1; i++)
    {
        
        int flag = 0;
        
        for (int j = i - 2; j <= i + 2; j++)
        {
            if (j >= 0 && j < n2)

            {
                char p[3];
                char q[3];

                snprintf(p, sizeof(p), "%c", a[i]);
                snprintf(q, sizeof(q), "%c", b[j]);

                int decidechar = strcasecmp(p, q);
                
                if (decidechar == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        
        if (flag == 1)
        {
            count++;
        }
    }

    if (count >= (n1 / 1.2))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int station(char Name[50])
{
    int i;
    // Purple line starts
    i = strcasecmp(Name, "PCMC");
    if (i == 0)
        return 0;

    i = strcasecmp(Name, "Sant Tukaram Nagar");
    if (i == 0)
    {
        return 1;
    }

    i = strcasecmp(Name, "Bhosari");
    if (i == 0)
    {
        return 2;
    }

    i = strcasecmp(Name, "Nashik Phata");
    if (i == 0)
        return 2;

    i = strcasecmp(Name, "Kasarwadi");
    if (i == 0)
        return 3;

    i = strcasecmp(Name, "Phugewadi");
    if (i == 0)
        return 4;
    i = strcasecmp(Name, "Dapodi");
    if (i == 0)
        return 5;
    i = strcasecmp(Name, "Bopodi");
    if (i == 0)
        return 6;

    i = strcasecmp(Name, "Khadaki");
    if (i == 0)
        return 7;

    i = strcasecmp(Name, "Range Hill");
    if (i == 0)
        return 8;

    i = strcasecmp(Name, "Shivaji Nagar");
    if (i == 0)
        return 9;

    i = strcasecmp(Name, "Budhwar Peth");
    if (i == 0)
        return 10;

    i = strcasecmp(Name, "Mandai");
    if (i == 0)
        return 11;

    i = strcasecmp(Name, "Swargate");
    if (i == 0)
        return 12;

    i = strcasecmp(Name, "Laxmi Narayan Talkies");
    if (i == 0)
        return 13;

    i = strcasecmp(Name, "Bhapkar Petrol Pump");
    if (i == 0)
        return 14;

    i = strcasecmp(Name, "Padmavati");
    if (i == 0)
        return 15;

    i = strcasecmp(Name, "Balaji Nagar");
    if (i == 0)
        return 16;

    i = strcasecmp(Name, "Bharti Vidyapeeth gate");
    if (i == 0)
        return 17;

    i = strcasecmp(Name, "Sarpodyan");
    if (i == 0)
        return 18;

    i = strcasecmp(Name, "Katraj");
    if (i == 0)
        return 19;

    // PURPLE LINE ENDS

    // Aqua line starts
    i = strcasecmp(Name, "Chandani Chowk");
    if (i == 0)
        return 20;

    i = strcasecmp(Name, "Vanaz");
    if (i == 0)
        return 21;

    i = strcasecmp(Name, "Anand Nagar");
    if (i == 0)
        return 22;

    i = strcasecmp(Name, "Ideal colony");
    if (i == 0)
        return 23;

    i = strcasecmp(Name, "Nal Stop");
    if (i == 0)
        return 24;

    i = strcasecmp(Name, "Garware College");
    if (i == 0)
        return 25;

    i = strcasecmp(Name, "Deccan Gymkhana");
    if (i == 0)
        return 26;

    i = strcasecmp(Name, "Chhatrapati Sambhaji Udyan");
    if (i == 0)
        return 27;

    i = strcasecmp(Name, "PMC");
    if (i == 0)
        return 28;

    i = strcasecmp(Name, "Civil Court"); //         Junction
    if (i == 0)
        return 29;

    i = strcasecmp(Name, "Mangalwar Peth");
    if (i == 0)
        return 30;

    i = strcasecmp(Name, "Pune Railway Station");
    if (i == 0)
        return 31;

    i = strcasecmp(Name, "Ruby Hall Clinic");
    if (i == 0)
        return 32;

    i = strcasecmp(Name, "Bund Garden");
    if (i == 0)
        return 33;

    i = strcasecmp(Name, "Yerawada");
    if (i == 0)
        return 34;

    i = strcasecmp(Name, "Kalayani Nagar");
    if (i == 0)
        return 35;

    i = strcasecmp(Name, "Ramwadi");
    if (i == 0)
        return 36;

    i = strcasecmp(Name, "Wadgaon Sheri Phata");
    if (i == 0)
        return 37;

    i = strcasecmp(Name, "Viman Nagar Corner");
    if (i == 0)
        return 38;

    i = strcasecmp(Name, "Tata Guardroom");
    if (i == 0)
        return 39;
    i = strcasecmp(Name, "Kharadi Bypass");
    if (i == 0)
        return 40;
    i = strcasecmp(Name, "Janak Baba Dargha");
    if (i == 0)
        return 41;
    i = strcasecmp(Name, "Aaple Ghar");
    if (i == 0)
        return 42;
    i = strcasecmp(Name, "Khandve Nagar");
    if (i == 0)
        return 43;

    i = strcasecmp(Name, "Ubale Nagar");
    if (i == 0)
        return 44;

    i = strcasecmp(Name, "Godown Talera");
    if (i == 0)
        return 45;

    i = strcasecmp(Name, "Soyrik Mangal Karyalay");
    if (i == 0)
        return 46;

    i = strcasecmp(Name, "Kamal Bagh");
    if (i == 0)
        return 47;

    i = strcasecmp(Name, "Wagholi");
    if (i == 0)
        return 48;

    // Aqua line ends

    // Line 3-HINJEWADI TO SHIVAJI NAGAR

    i = strcasecmp(Name, "Metropolic Circle");
    if (i == 0)
        return 49;

    i = strcasecmp(Name, "Embassy quadron business park");
    if (i == 0)
        return 50;

    i = strcasecmp(Name, "Dohler");
    if (i == 0)
        return 51;

    i = strcasecmp(Name, "Infosys Phase 2");
    if (i == 0)
        return 52;

    i = strcasecmp(Name, "Pall India");
    if (i == 0)
        return 53;

    i = strcasecmp(Name, "Shivaji Chowk");
    if (i == 0)
        return 54;

    i = strcasecmp(Name, "Hinjewadi");
    if (i == 0)
        return 55;

    i = strcasecmp(Name, "Wakad Chowk");
    if (i == 0)
        return 56;

    i = strcasecmp(Name, "Balewadi Stadium");
    if (i == 0)
        return 57;

    i = strcasecmp(Name, "NICMAR");
    if (i == 0)
        return 58;

    i = strcasecmp(Name, "Ram Nagar");
    if (i == 0)
        return 59;

    i = strcasecmp(Name, "Laxmi Nagar");
    if (i == 0)
        return 60;

    i = strcasecmp(Name, "Balewadi Phata");
    if (i == 0)
        return 61;

    i = strcasecmp(Name, "Banergaon");
    if (i == 0)
        return 62;

    i = strcasecmp(Name, "Baner");
    if (i == 0)
        return 63;

    i = strcasecmp(Name, "Krushi Anusadhan");
    if (i == 0)
        return 64;

    i = strcasecmp(Name, "Sakal Nagar");
    if (i == 0)
        return 65;

    i = strcasecmp(Name, "University");
    if (i == 0)
        return 66;

    i = strcasecmp(Name, "RBI");
    if (i == 0)
        return 67;

    i = strcasecmp(Name, "Agriculture College");
    if (i == 0)
        return 68;

    // Line 3 ends

    // Line 4 starts
    i = strcasecmp(Name, "Kharadi Chowk");
    if (i == 0)
        return 69;

    i = strcasecmp(Name, "Colombia Asia Hospital");
    if (i == 0)
        return 70;

    i = strcasecmp(Name, "Mundhawa Chowk");
    if (i == 0)
        return 71;

    i = strcasecmp(Name, "Spring Valley Apartment");
    if (i == 0)
        return 72;

    i = strcasecmp(Name, "Magarpatta Manapa Shala");
    if (i == 0)
        return 73;

    i = strcasecmp(Name, "Tilekar Vaoti");
    if (i == 0)
        return 74;

    i = strcasecmp(Name, "Hadapsar MIDC");
    if (i == 0)
        return 75;

    i = strcasecmp(Name, "Fatima Nagar");
    if (i == 0)
        return 76;

    i = strcasecmp(Name, "Race Course");
    if (i == 0)
        return 77;

    i = strcasecmp(Name, "AFMC");
    if (i == 0)
        return 77;

    i = strcasecmp(Name, "Golibar Maidan");
    if (i == 0)
        return 78;
    i = strcasecmp(Name, "Saras Baug");
    if (i == 0)
        return 79;

    i = strcasecmp(Name, "Dandekar Pool");
    if (i == 0)
        return 80;
        
    i = strcasecmp(Name, "Ganesh Mala");
    if (i == 0)
        return 81;
    i = strcasecmp(Name, "Rajaram Pul");
    if (i == 0)
        return 82;
    i = strcasecmp(Name, "Manik Baug");
    if (i == 0)
        return 83;
    i = strcasecmp(Name, "Vadagaon Khurd Phata");
    if (i == 0)
        return 84;
    i = strcasecmp(Name, "Patil Colony");
    if (i == 0)
        return 85;
    i = strcasecmp(Name, "Dhayari Phata");
    if (i == 0)
        return 86;
    i = strcasecmp(Name, "Lagadmala");
    if (i == 0)
        return 87;

    i = strcasecmp(Name, "Mate Pat");
    if (i == 0)
        return 88;
    i = strcasecmp(Name, "Nanded City");
    if (i == 0)
        return 89;
    i = strcasecmp(Name, "Khadakwasala");
    if (i == 0)
        return 90;
    else
    {
        return -50;
    }

    // Line 4 ends
}

int StationNotFound(char *Name)
{
    int i, data, j = 0;

    printf("Did you mean:-");
    // Purple line starts
    i = Check_Station(Name, "PCMC");
    if (i == 1)
    {
        printf("PCMC  (search key)->0\n");
        j = 1;

        data = 0;
        push(data);
    }

    i = Check_Station(Name, "Sant Tukaram Nagar");
    if (i == 1)
    {
        printf("Sant Tukaram Nagar (search key)->1\n");
        j = 1;

        data = 1;
        push(data);
    }

    i = Check_Station(Name, "Bhosari");
    if (i == 1)
    {
        printf("Bhosari(search key)->2\n");
       
        j = 1;

        data = 2;
        push(data);
    }

    i = Check_Station(Name, "Nashik Phata");
    if (i == 1)
    {
        printf("Nashik Phata(search key)->2\n");
        j = 1;

        data = 2;
        push(data);
    }

    i = Check_Station(Name, "Kasarwadi");
    if (i == 1)
    {
        printf("Kasarwadi  (search key)->3\n");
        j = 1;

        data = 3;
        push(data);
    }

    i = Check_Station(Name, "Phugewadi");
    if (i == 1)
    {
        printf("Phugewadi  (search key)->4\n");
        j = 1;

        data = 4;
        push(data);
    }

    i = Check_Station(Name, "Dapodi");
    if (i == 1)
    {
        printf("Dapodi (search key)->5\n");
        j = 1;

        data = 5;
        push(data);
    }

    i = Check_Station(Name, "Bopodi");
    if (i == 1)
    {
        printf("Bopodi  (search key)->6\n");
        j = 1;

        data = 6;
        push(data);
    }

    i = Check_Station(Name, "Khadaki");
    if (i == 1)
    {
        printf("Khadaki  (search key)->7\n");
        j = 1;

        data = 7;
        push(data);
    }

    i = Check_Station(Name, "Range Hill");
    if (i == 1)
    {
        printf("Range Hill  (search key)->8\n");
        j = 1;

        data = 8;
        push(data);
    }

    i = Check_Station(Name, "Shivaji Nagar");
    if (i == 1)
    {
        printf("Shivaji Nagar  (search key)->9\n");
        j = 1;

        data = 9;
        push(data);
    }

    i = Check_Station(Name, "Budhwar Peth");
    if (i == 1)
    {
        printf("Budhwar Peth  (search key)->10\n");
        j = 1;

        data = 10;
        push(data);
    }

    i = Check_Station(Name, "Mandai");
    if (i == 1)
    {
        printf("Mandai (search key)->11\n");
        j = 1;

        data = 11;
        push(data);
    }

    i = Check_Station(Name, "Swargate");
    if (i == 1)
    {
        printf("Swargate  (search key)->12\n");
        j = 1;

        data = 12;
        push(data);
    }

    i = Check_Station(Name, "Laxmi Narayan Talkies");
    if (i == 1)
    {
        printf("Laxmi Narayan Talkies  (search key)->13\n");
        j = 1;

        data = 13;
        push(data);
    }

    i = Check_Station(Name, "Bhapkar Petrol Pump");
    if (i == 1)
    {
        printf("Bhapkar Petrol Pump  (search key)->14\n");
        j = 1;

        data = 14;
        push(data);
    }

    i = Check_Station(Name, "Padmavati");
    if (i == 1)
    {
        printf("Padmavati  (search key)->15\n");
        j = 1;

        data = 15;
        push(data);
    }

    i = Check_Station(Name, "Balaji Nagar");
    if (i == 1)
    {
        printf("Balaji Nagar  (search key)-> 16\n");
        j = 1;

        data = 16;
        push(data);
    }

    i = Check_Station(Name, "Bharti Vidyapeeth Gate");
    if (i == 1)
    {
        printf("Bharti Vidyapeeth Gate  (search key)-> 17\n");
        j = 1;

        data = 17;
        push(data);
    }

    i = Check_Station(Name, "Sarpodyan");
    if (i == 1)
    {
        printf("Sarpodyan  (search key)-> 18\n");
        j = 1;

        data = 18;
        push(data);
    }

    i = Check_Station(Name, "Katraj");
    if (i == 1)
    {
        printf("Katraj  (search key)-> 19\n");
        j = 1;

        data = 19;
        push(data);
    }

    // PURPLE LINE ENDS

    // Aqua line starts
    i = Check_Station(Name, "Chandani Chowk");
    if (i == 1)
    {
        printf("Chandani Chowk (search key)->20\n");
        j = 1;

        data = 20;
        push(data);
    }

    i = Check_Station(Name, "Vanaz");
    if (i == 1)
    {
        printf("Vanaz (search key)->21\n");
        j = 1;

        data = 21;
        push(data);
    }

    i = Check_Station(Name, "Anand Nagar");
    if (i == 1)
    {
        printf("Anand Nagar  (search key)->22\n");
        j = 1;

        data = 22;
        push(data);
    }

    i = Check_Station(Name, "Ideal colony");
    if (i == 1)
    {
        printf("Ideal colony  (search key)->23\n");
        j = 1;

        data = 23;
        push(data);
    }

    i = Check_Station(Name, "Nal Stop");
    if (i == 1)
    {
        printf("Nal Stop  (search key)->24\n");
        j = 1;

        data = 24;
        push(data);
    }

    i = Check_Station(Name, "Garware College");
    if (i == 1)
    {
        printf("Garware College  (search key)->25\n");
        j = 1;

        data = 25;
        push(data);
    }

    i = Check_Station(Name, "Deccan Gymkhana");
    if (i == 1)
    {
        printf("Deccan Gymkhana  (search key)->26\n");
        j = 1;

        data = 26;
        push(data);
    }

    i = Check_Station(Name, "Chhatrapati Sambhaji Udyan");
    if (i == 1)
    {
        printf("Chhatrapati Sambhaji Udyan (search key)->27\n");
        j = 1;

        data = 27;
        push(data);
    }

    i = Check_Station(Name, "PMC");
    if (i == 1)
    {
        printf("PMC (search key)->28\n");
        j = 1;

        data = 28;
        push(data);
    }

    i = Check_Station(Name, "Civil Court");
    if (i == 1)
    {
        printf("Civil Court  (search key)->29\n");
        j = 1;

        data = 29;
        push(data);
    }

    i = Check_Station(Name, "Mangalwar Peth");
    if (i == 1)
    {
        printf("Mangalwar Peth  (search key)->30\n");
        j = 1;

        data = 30;
        push(data);
    }

    i = Check_Station(Name, "Pune Railway Station");
    if (i == 1)
    {
        printf("Pune Railway Station  (search key)->31\n");
        j = 1;

        data = 31;
        push(data);
    }

    i = Check_Station(Name, "Ruby Hall Clinic");
    if (i == 1)
    {
        printf("Ruby Hall Clinic  (search key)->32\n");
        j = 1;

        data = 32;
        push(data);
    }

    i = Check_Station(Name, "Bund Garden");
    if (i == 1)
    {
        printf("Bund Garden  (search key)->33\n");
        j = 1;

        data = 33;
        push(data);
    }

    i = Check_Station(Name, "Yerawada");
    if (i == 1)
    {
        printf("Yerawada  (search key)->34\n");
        j = 1;

        data = 34;
        push(data);
    }

    i = Check_Station(Name, "Kalayani Nagar");
    if (i == 1)
    {
        printf("Kalayani Nagar  (search key)->35\n");
        j = 1;

        data = 35;
        push(data);
    }

    i = Check_Station(Name, "Ramwadi");
    if (i == 1)
    {
        printf("Ramwadi (search key)->36\n");
        j = 1;

        data = 36;
        push(data);
    }

    i = Check_Station(Name, "Wadgaon Sheri Phata");
    if (i == 1)
    {
        printf("Wadgaon Sheri Phata (search key)->37\n");

        j = 1;

        data = 37;
        push(data);
    }

    i = Check_Station(Name, "Viman Nagar Corner");
    if (i == 1)
    {
        printf("Viman Nagar Corner  (search key)->38\n");
        j = 1;

        data = 38;
        push(data);
    }

    i = Check_Station(Name, "Tata Guardroom");
    if (i == 1)
    {
        printf("Tata Guardroom  (search key)->39\n");
        j = 1;

        data = 39;
        push(data);
    }

    i = Check_Station(Name, "Kharadi Bypass");
    if (i == 1)
    {
        printf("Kharadi Bypass (search key)->40\n");
        j = 1;

        data = 40;
        push(data);
    }

    i = Check_Station(Name, "Janak Baba Dargha");
    if (i == 1)
    {
        printf("Janak Baba Dargha  (search key)->41\n");
        j = 1;

        data = 41;
        push(data);
    }

    i = Check_Station(Name, "Aaple Ghar");
    if (i == 1)
    {
        printf("Aaple Ghar (search key)->42\n");
        j = 1;

        data = 42;
        push(data);
    }

    i = Check_Station(Name, "Khandve Nagar");
    if (i == 1)
    {
        printf("Khandve Nagar  (search key)->43\n");
        j = 1;

        data = 43;
        push(data);
    }

    i = Check_Station(Name, "Ubale Nagar");
    if (i == 1)
    {
        printf("Ubale Nagar (search key)->44\n");
        j = 1;

        data = 44;
        push(data);
    }

    i = Check_Station(Name, "Godown Talera");
    if (i == 1)
    {
        printf("Godown Talera (search key)->45\n");
        j = 1;

        data = 45;
        push(data);
    }

    i = Check_Station(Name, "Soyrik Mangal Karyalay");
    if (i == 1)
    {
        printf("Soyrik Mangal Karyalay  (search key)->46\n");
        j = 1;

        data = 46;
        push(data);
    }

    i = Check_Station(Name, "Kamal Bagh");
    if (i == 1)
    {
        printf("Kamal Bagh  (search key)->47\n");
        j = 1;

        data = 47;
        push(data);
    }

    i = Check_Station(Name, "Wagholi");
    if (i == 1)
    {
        printf("Wagholi  (search key)->48\n");
        j = 1;

        data = 48;
        push(data);
    }
    // Aqua line ends

    // LINE 3- Hinjewadi to Shivajinagar

    i = Check_Station(Name, "Metropolic Circle");
    if (i == 1)
    {
        printf("Metropolic Circle (search key)->49\n");
        j = 1;

        data = 49;
        push(data);
    }

    i = Check_Station(Name, "Embassy quadron business park");
    if (i == 1)
    {
        printf("Embassy quadron business park  (search key)->50\n");
        j = 1;

        data = 50;
        push(data);
    }

    i = Check_Station(Name, "Dohler");
    if (i == 1)
    {
        printf("Dohler  (search key)->51\n");
        j = 1;

        data = 51;
        push(data);
    }

    i = Check_Station(Name, "Infosys Phase 2");
    if (i == 1)
    {
        printf("Infosys Phase 2 (search key)->52\n");
        j = 1;

        data = 52;
        push(data);
    }

    i = Check_Station(Name, "Pall India");
    if (i == 1)
    {
        printf("Pall India (search key)->53\n");
        j = 1;

        data = 53;
        push(data);
    }

    i = Check_Station(Name, "Shivaji Chowk");
    if (i == 1)
    {
        printf("Shivaji Chowk (search key)->54\n");
        j = 1;

        data = 54;
        push(data);
    }

    i = Check_Station(Name, "Hinjewadi");
    if (i == 1)
    {
        printf("Hinjewadi (search key)->55\n");
        j = 1;

        data = 55;
        push(data);
    }

    i = Check_Station(Name, "Wakad Chowk");
    if (i == 1)
    {
        printf("Wakad Chowk  (search key)->56\n");
        j = 1;

        data = 56;
        push(data);
    }

    i = Check_Station(Name, "Balewadi Stadium");
    if (i == 1)
    {
        printf("Balewadi Stadium (search key)->57\n");
        j = 1;

        data = 57;
        push(data);
    }

    i = Check_Station(Name, "NICMAR");
    if (i == 1)
    {
        printf("NICMAR  (search key)->58\n");
        j = 1;

        data = 58;
        push(data);
    }

    i = Check_Station(Name, "Ram Nagar");
    if (i == 1)
    {
        printf("Ram Nagar (search key)->59\n");
        j = 1;

        data = 59;
        push(data);
    }

    i = Check_Station(Name, "Laxmi Nagar");
    if (i == 1)
    {
        printf("Laxmi Nagar (search key)->60\n");
        j = 1;

        data = 60;
        push(data);
    }

    i = Check_Station(Name, "Balewadi Phata");
    if (i == 1)
    {
        printf("Balewadi Phata (search key)->61\n");
        j = 1;

        data = 61;
        push(data);
    }

    i = Check_Station(Name, "Banergaon");
    if (i == 1)
    {
        printf("Banergaon  (search key)->62\n");
        j = 1;

        data = 62;
        push(data);
    }

    i = Check_Station(Name, "Baner");
    if (i == 1)
    {
        printf("Baner (search key)->63\n");
        j = 1;

        data = 63;
        push(data);
    }

    i = Check_Station(Name, "Krushi Anusadhan");
    if (i == 1)
    {
        printf("Krushi Anusadhan (search key)->64\n");
        j = 1;

        data = 64;
        push(data);
    }

    i = Check_Station(Name, "Sakal Nagar");
    if (i == 1)
    {
        printf("Sakal Nagar  (search key)->65\n");
        j = 1;

        data = 65;
        push(data);
    }

    i = Check_Station(Name, "University");
    if (i == 1)
    {
        printf("University (search key)->66\n");
        j = 1;

        data = 66;
        push(data);
    }

    i = Check_Station(Name, "RBI");
    if (i == 1)
    {
        printf("RBI  (search key)->67\n");
        j = 1;

        data = 67;
        push(data);
    }

    i = Check_Station(Name, "Agriculture College");
    if (i == 1)
    {
        printf("Agriculture College  (search key)->68\n");
        j = 1;

        data = 68;
        push(data);
    }

    // Line 3 ends

    // Line 4
    i = Check_Station(Name, "Kharadi Chowk");
    if (i == 1)
    {
        printf("Kharadi Chowk  (search key)->69\n");
        j = 1;

        data = 69;
        push(data);
    }

    i = Check_Station(Name, "Colombia Asia Hospital");
    if (i == 1)
    {
        printf("Colombia Asia Hospital  (search key)->70\n");
        j = 1;

        data = 70;
        push(data);
    }

    i = Check_Station(Name, "Mundhawa Chowk");
    if (i == 1)
    {
        printf("Mundhawa Chowk  (search key)->71\n");
        j = 1;

        data = 71;
        push(data);
    }

    i = Check_Station(Name, "Spring Valley Apartment");
    if (i == 1)
    {
        printf("Spring Valley Apartment  (search key)->72\n");
        j = 1;

        data = 72;
        push(data);
    }

    i = Check_Station(Name, "Magarpatta Manapa Shala");
    if (i == 1)
    {
        printf("Magarpatta Manapa Shala  (search key)->73\n");
        j = 1;

        data = 73;
        push(data);
    }

    i = Check_Station(Name, "Tilekar Vaoti");
    if (i == 1)
    {
        printf("Tilekar Vaoti  (search key)->74\n");
        j = 1;

        data = 74;
        push(data);
    }

    i = Check_Station(Name, "Hadapsar MIDC");
    if (i == 1)
    {
        printf("Hadapsar MIDC  (search key)->75\n");
        j = 1;

        data = 75;
        push(data);
    }

    i = Check_Station(Name, "Fatima Nagar");
    if (i == 1)
    {
        printf("Fatima Nagar  (search key)->76\n");
        j = 1;

        data = 76;
        push(data);
    }

    i = Check_Station(Name, "Race Course");
    if (i == 1)
    {
        printf("Race Course  (search key)->77\n");
        j = 1;

        data = 77;
        push(data);
    }

    i = Check_Station(Name, "AFMC");
    if (i == 1)
    {
        printf("AFMC  (search key)->77\n");
        j = 1;

        data = 77;
        push(data);
    }

    i = Check_Station(Name, "Golibar Maidan");
    if (i == 1)
    {
        printf("Golibar Maidan  (search key)->78\n");
        j = 1;

        data = 78;
        push(data);
    }

    i = Check_Station(Name, "Saras Baug");
    if (i == 1)
    {
        printf("Saras Baug  (search key)->79\n");
        j = 1;

        data = 79;
        push(data);
    }

    i = Check_Station(Name, "Dandekar Pool");
    if (i == 1)
    {
        printf("Dandekar Pool  (search key)->80\n");
        j = 1;

        data = 80;
        push(data);
    }

    i = Check_Station(Name, "Ganesh Mala");
    if (i == 1)
    {
        printf("Ganesh Mala  (search key)->81\n");
        j = 1;

        data = 81;
        push(data);
    }

    i = Check_Station(Name, "Rajaram Pul");
    if (i == 1)
    {
        printf("Rajaram Pul  (search key)->82\n");
        j = 1;

        data = 82;
        push(data);
    }

    i = Check_Station(Name, "Manik Baug");
    if (i == 1)
    {
        printf("Manik Baug  (search key)->83\n");
        j = 1;

        data = 83;
        push(data);
    }

    i = Check_Station(Name, "Vadagaon Khurd Phata");
    if (i == 1)
    {
        printf("Vadagaon Khurd Phata  (search key)->84\n");
        j = 1;

        data = 84;
        push(data);
    }

    i = Check_Station(Name, "Patil Colony");
    if (i == 1)
    {
        printf("Patil Colony  (search key)->85\n");
        j = 1;

        data = 85;
        push(data);
    }

    i = Check_Station(Name, "Dhayari Phata");
    if (i == 1)
    {
        printf("Dhayari Phata  (search key)->86\n");
        j = 1;

        data = 86;
        push(data);
    }

    i = Check_Station(Name, "Lagadmala");
    if (i == 1)
    {
        printf("Lagadmala  (search key)->87\n");
        j = 1;

        data = 87;
        push(data);
    }

    i = Check_Station(Name, "Mate Pat");
    if (i == 1)
    {
        printf("Mate Pat  (search key)->88\n");
        j = 1;

        data = 88;
        push(data);
    }

    i = Check_Station(Name, "Nanded City");
    if (i == 1)
    {
        printf("Nanded City  (search key)->89\n");
        j = 1;

        data = 89;
        push(data);
    }

    i = Check_Station(Name, "Khadakwasala");
    if (i == 1)
    {
        printf("Khadakwasala  (search key)->90\n");
        j = 1;

        data = 90;
        push(data);
    }

    if (j == 1)
    {
        return 1;
    }
    else if (j == 0)
    {
        return -51;
    }
    // Line 4 ends
}

void createGraph() // This function connects stations according to Pune Metro routes
{

    int i;
    adj[0][1] = 2.1; // PCMC TO SANT TUKARAM NAGAR
    adj[1][0] = 2.1;

    adj[1][2] = 0.7; // SANT TUKARAM NAGAR TO BHOSARI
    adj[2][1] = 0.7;

    adj[2][3] = 1.5; // BHOSARI TO KASARWADI
    adj[3][2] = 1.5;

    adj[3][4] = 1.1; // KASARWADI TO PHUGEWADI
    adj[4][3] = 1.1;

    adj[4][5] = 2.4; // PHUGEWADI TO DAPODI
    adj[5][4] = 2.4;

    adj[5][6] = 1; // DAPODI TO BHOPODI
    adj[6][5] = 1;

    adj[6][7] = 1.4; // BHOPODI TO KHADKI
    adj[7][6] = 1.4;

    adj[7][8] = 5.3; // KHADKI TO RANGE HILLS
    adj[8][7] = 5.3;

    adj[8][9] = 2.9; // RANGE HILL TO SHIVAJINAGAR
    adj[9][8] = 2.9;

    adj[9][29] = 1; // SHIVAJINAGAR TO CIVIL COURT
    adj[29][9] = 1;

    adj[29][10] = 1.1; // CIVIL COURT TO BUDHWAR PETH
    adj[10][29] = 1.1;

    adj[10][11] = 0.65; // BUDHWAR PETH TO MANDAI
    adj[11][10] = 0.65;

    adj[11][12] = 1.7; // MANDAI TO SWARGATE
    adj[12][11] = 1.7;

    adj[12][13] = 0.4; // SWARGATE TO LNT
    adj[13][12] = 0.4;

    adj[13][14] = 1.3; // LNT TO BPP
    adj[14][13] = 1.3;

    adj[14][15] = 1.6; // BPP TO PDMV
    adj[15][14] = 1.6;

    adj[15][16] = 1.6; // PDMV TO BALAJINAGAR
    adj[16][15] = 1.6;

    adj[16][17] = 0.8; // B NGR TO BVP
    adj[17][16] = 0.8;

    adj[17][18] = 1.1; // BVP TO SARPODYAN
    adj[18][17] = 1.1;

    adj[18][19] = 0.9; // SARP TO KATRAJ
    adj[19][18] = 0.9;

    // adj[19][20] = 4;
    // adj[20][19] = 4;

    // AQUALINE STARTS - CHANDANI CHOWK - VANAZ - RAMWADI - WAGHOLI

    adj[20][21] = 1.15; // CC TO VANAZ
    adj[21][20] = 1.15;

    adj[21][22] = 1.8; // VANAZ TO ANANDNAGAR
    adj[22][21] = 1.8;

    adj[22][23] = 1.7; // ANANADNAGAR TO IDEAL COLONY
    adj[23][22] = 1.7;

    adj[23][24] = 1.5; // IDEAL COLONY TO NAL STOP
    adj[24][23] = 1.5;

    adj[24][25] = 1.8; // NAL STOP TO GARWARE COLLEGE
    adj[25][24] = 1.8;

    adj[25][26] = 1; // GARWARE COLLEGE TO DECCAN
    adj[26][25] = 1;

    adj[26][27] = 0.8; // DECCAN TO CHH SAMBHAJI GARDEN
    adj[27][26] = 0.8;

    adj[27][28] = 0.8; // SAMBHAJI GARDEN TO PMC
    adj[28][27] = 0.8;

    adj[28][29] = 0.8; // PMC TO CIVIL COURT
    adj[29][28] = 0.8;

    adj[29][30] = 1.5; // CIVIL COURT TO MANGALWAR PETH
    adj[30][29] = 1.5;

    adj[30][31] = 1.3; // MANGALWAR PETH TO PUNE RAILWAY STATION
    adj[31][30] = 1.3;

    adj[31][32] = 0.9; // PUNE STATION TO RUBY
    adj[32][31] = 0.9;

    adj[32][33] = 1.3; // RUBY TO BUND GARDEN
    adj[33][32] = 1.3;

    adj[33][34] = 1; // BUND TO YERAWADA
    adj[34][33] = 1;

    adj[34][35] = 2.5; // YERAWADA TO KALYANI NAGAR
    adj[35][34] = 2.5;

    adj[35][36] = 3; // KALYANI NAGAR TO RAMWADI
    adj[36][35] = 3;

    adj[36][37] = 1.2; // RAMWADI TO WAGDAON SHERI PHATA
    adj[37][36] = 1.2;

    adj[37][38] = 1.4; // WADGAON SHERI PHATA TO VIMAN NAGAR
    adj[38][37] = 1.4;

    adj[38][39] = 1.4; // VIMAN NAGAR TO TATA GUARDROOM
    adj[39][38] = 1.4;

    adj[39][40] = 1.2; // TATA GUARDROOM TO KHARADI BYPASS
    adj[40][39] = 1.2;

    adj[40][41] = 0.75; // KHARADI BYPASS TO JANAK BABA
    adj[41][40] = 0.75;

    adj[41][42] = 2; // JANAK BABA TO AAPLE GHAR
    adj[42][41] = 2;

    adj[42][43] = 2.4; // AAPLE GHAR TO KHANDVE NAAGAR
    adj[43][42] = 2.4;

    adj[43][44] = 1.3; // KHANDVE NAGAR TO UBALENAGAR
    adj[44][43] = 1.3;

    adj[44][45] = 1.8; // UBALENAGAR TO GODOWN TALERA
    adj[45][44] = 1.8;

    adj[45][46] = 0.75; // GODOWN TALERA TO SOYRIK
    adj[46][45] = 0.75;

    adj[46][47] = 1.4; // SOYRIK TO KAMAL BAGH
    adj[47][46] = 1.4;

    adj[47][48] = 4; // KAMAL BAGH TO WAGHOLI
    adj[48][47] = 4;

    // AQUALINE FINISHED

    // YELLOW LINE - Hinjewadi to Shivajinagar

    adj[49][50] = 1.5; // METROPOLIC CIRCLE TO EMBASSY Q BUSINESS PARK
    adj[50][49] = 1.5;

    adj[50][51] = 1; // EMBASSY TO DOHLER
    adj[51][50] = 1;

    adj[51][52] = 1.1; // DOHLER TO INFOSYS PHASE 2
    adj[52][51] = 1.1;

    adj[52][53] = 1.2; // INFOSYS PHASE 2 TO WIPRO PHASE 2
    adj[53][52] = 1.2;

    adj[53][54] = 0.85; // WIPRO PHASE 2 TO PALL INDIA
    adj[54][53] = 0.85;

    adj[54][55] = 1.7; // PALL INDIA TO SHIVAJI CHOWK
    adj[55][54] = 1.7;

    adj[55][56] = 1.6; // SHIVAJI CHOWK TO HINJEWADI
    adj[56][55] = 1.6;

    adj[56][57] = 1.2; // HINJEWADI TO WAKAD CHOWK
    adj[57][56] = 1.2;

    adj[57][58] = 1.6; // WAKAD CHOWK TO BALEWADI STADIUM
    adj[58][57] = 1.6;

    adj[58][59] = 1.4; // BALEWADI STDM TO NICMAR
    adj[59][58] = 1.4;

    adj[59][60] = 0.8; // NICMAR TO RAMNAGAR
    adj[60][59] = 0.8;

    adj[60][61] = 2.1; // RAMNAGAR TO BALEWADI PHATA
    adj[61][60] = 2.1;

    adj[61][62] = 1; // BALEWADI PHATA TO BANERGAON
    adj[62][61] = 1;

    adj[62][63] = 1; // BANERGAON TO BANER
    adj[63][62] = 1;

    adj[63][64] = 0.9; // BANER TO KRUSHI ANU
    adj[64][63] = 0.9;

    adj[64][65] = 1.5; // KRUSHI TO SAKAL NAGAR
    adj[65][64] = 1.5;

    adj[65][66] = 1.4; // SAKAL NAGAR TO UNIVERSITY
    adj[66][65] = 1.4;

    adj[66][67] = 1.1; // UNIVERSITY TO RBI
    adj[67][66] = 1.1;

    adj[67][68] = 1; // RBI TO AGRICULTURE COLLEGE
    adj[68][67] = 1;

    adj[68][9] = 0.8; // AGRI CLG TO SHIVAJINAGAR
    adj[9][68] = 0.8;

    adj[9][29] = 1; // SHIVAJINAGAR TO CIVIL COURT
    adj[29][9] = 1;

    adj[69][70] = 1.8; // KHARADI CHOWK TO COLOMBIA ASIA HOSPITAL
    adj[70][69] = 1.8;

    adj[70][71] = 1.4; // COLOMBIA ASIA HOSPITAL TO MUNDWA CHOWK
    adj[71][70] = 1.4;

    adj[71][72] = 1; // MUNDWA CHOWK TO SPRING VALLEY APARTMENT
    adj[72][71] = 1;

    adj[72][73] = 1.7; // SPRING VALLEY APARTMENT TO MAGARPATTA MANAPA SHALA
    adj[73][72] = 1.7;

    adj[73][74] = 2.1; // MAGARPATTA MANAPA SHALA TO TILEKAR VAOTI
    adj[74][73] = 2.1;

    adj[74][75] = 2.4; // TILEKAR VAOTI TO HADAPSAR MIDC
    adj[75][74] = 2.4;

    adj[75][76] = 0.9; //  HADAPSAR MIDC TO FATIMA NAGAR
    adj[76][75] = 0.9;

    adj[76][77] = 2.5; //  FATIMA NAGAR TO RACE COURSE/AFMC
    adj[77][76] = 2.5;

    adj[77][78] = 1.8; // RACE COURSE/AFMC TO GOLIBAR MAIDAN
    adj[78][77] = 1.8;

    adj[78][12] = 1.6; // GOLIBAR MAIDAN TO SWARGATE
    adj[12][78] = 1.6;

    adj[12][79] = 2; // SWARGATE TO SARAS BAUG
    adj[79][12] = 2;

    adj[79][80] = 1.5; // SARAS BAUG TO DANDEKAR POOL
    adj[80][79] = 1.5;

    adj[80][81] = 1.2; // DANDEKAR POOL TO GANESH MALA
    adj[81][80] = 1.2;

    adj[81][82] = 1.3; //GANESH MALA TO RAJARAM PUL 
    adj[82][81] = 1.3;

    adj[82][83] = 1.6; //RAJARAM PUL TO MANIK BAUG 
    adj[83][82] = 1.6;

    adj[83][84] = 1.9; //MANIK BAUG TO VADAGAON KHURD PHATA 
    adj[84][83] = 1.9;

    adj[84][85] = 1.3; // VADAGAON KHURD PHATA  TO PATIL COLONY
    adj[85][84] = 1.3;

    adj[85][86] = 0.9; //PATIL COLONY TO DHAYARI PHATA
    adj[86][85] = 0.9;

    adj[86][87] = 2.7; //DHAYARI PHATA TO LAGADMALA 
    adj[87][86] = 2.7;

    adj[87][88] = 2.3; //LAGADMALA TO MATE PAT
    adj[88][87] = 2.3;

    adj[88][89] = 0.6; //MATE PAT TO NANDED CITY
    adj[89][88] = 0.6;

    adj[89][90] = 2.6; //NANDED CITY TO KHADAKWASALA
    adj[90][89] = 2.6;
}


int main()
{
    printf("\n\n\t\t\t\t\t PUNE METRO CONNECT\n\n\n");
    char sourceName[50];
    char destinationName[50];

    int sourceNumber, destinationNumber, manualNumber, item, manualNumber1;
    int manualcheck;
    float weight;
    char *sourceColor;
    char *destinationColor;

    Give_color_to_station();

    printf("Enter the Source Station Name:-");
    scanf(" %30[^\n]%*c", sourceName);

    //Get the source number from station function
    sourceNumber = station(sourceName);

    
    //If it did not matched with valid keywords in station func , it will return -50
    if (sourceNumber == -50)
    {
        //Then we provide that source name to StationNotFound function which assists us by 
        manualNumber = StationNotFound(sourceName);
        //If stationNotFound func returns -51 it means it was unable to match characters entered by user
        if (manualNumber == -51)
        {
            printf("No Stations Found!\n");
            exit(1);
        }
        else
        {
            printf("If your required station is listed then enter the search key:-");
            scanf("%d", &manualNumber);
            while (top != -1)
            {
                item = pop(); // Stack is used to avoid any wrong inputs
                if (manualNumber == item)
                {
                    sourceNumber = manualNumber;
                    top = -1;
                    manualcheck = -1;
                    break;
                }
            }
            if (manualcheck != -1)
            {
                printf("Program Terminated\n");
                exit(1);
            }
        }
    }
    //Get the source color from source number
    sourceColor = color[sourceNumber];

    printf("Enter the Destination Station Name:-");
    scanf(" %30[^\n]%*c", destinationName);

    destinationNumber = station(destinationName);
    if (destinationNumber == -50)
    {
        manualNumber1 = StationNotFound(destinationName);
        if (manualNumber1 == -51)
        {
            printf("No Stations Found!\n");
            exit(1);
        }
        else
        {
            printf("If your required station is listed then enter the search key:-");
            scanf("%d", &manualNumber1);
            while (top != -1)
            {
                item = pop(); // Stack is used to avoid any wrong inputs
                if (manualNumber1 == item)
                {
                    destinationNumber = manualNumber1;
                    top = -1;
                    manualcheck = -1;
                    break;
                }
            }
            if (manualcheck != -1)
            {
                printf("Program Terminated\n");
                exit(1);
            }
        }
    }

    //Get the destination color
    destinationColor = color[destinationNumber];

    // Find Route
    printf("\n");

    //Call the create graph function - it updates adjacency matrix with distance in km between src and dest - undirected graph used 
    createGraph();

    //Error handling - when src and dest are same
    if (destinationNumber == sourceNumber)
    {
        printf("Source and Destination Stations are the same\n");
        exit(1);
    }


    //Apply Dijkstra Algorithm on given source and destination
    dijkstra(sourceNumber, destinationNumber);


    findPath(sourceNumber, destinationNumber, sourceColor);
    weight = dist[destinationNumber];

    printf("\nAnd the you will reach your Final Destination\n");

    // display_time(sourceNumber, station1, station2);
    printf("\nYou have to travel %.2f Km\n", weight);
   
    if (weight <= 25)
    {
        printf("\nFare required:-Rs.%d \n", 10);
    }
    else
    {
        printf("Fare required:-Rs.%d\n", 20);
    }


    return 0;
}
