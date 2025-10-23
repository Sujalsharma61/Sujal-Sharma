#include <iostream>
#include <string>

using namespace std;

// Number of questions in the quiz
const int NUM_QUESTIONS = 10;

// Quiz questions and answers stored in arrays
string questions[] = {
    "What is the capital of France?",
    "Who wrote 'Romeo and Juliet'?",
    "What is the largest planet in our Solar System?",
    "How many continents are there on Earth?",
    "What is the chemical symbol for water?",
    "What is the square root of 64?",
    "What is the capital of Japan?",
    "Who painted the Mona Lisa?",
    "What is the smallest prime number?",
    "What is the boiling point of water at sea level (in °C)?"
};

string options[NUM_QUESTIONS][4] = {
    {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"},
    {"1. Charles Dickens", "2. William Shakespeare", "3. J.K. Rowling", "4. Mark Twain"},
    {"1. Earth", "2. Mars", "3. Jupiter", "4. Saturn"},
    {"1. 5", "2. 6", "3. 7", "4. 8"},
    {"1. H2O", "2. CO2", "3. NaCl", "4. O2"},
    {"1. 6", "2. 8", "3. 7", "4. 9"},
    {"1. Tokyo", "2. Kyoto", "3. Osaka", "4. Nagoya"},
    {"1. Vincent van Gogh", "2. Michelangelo", "3. Leonardo da Vinci", "4. Pablo Picasso"},
    {"1. 1", "2. 2", "3. 3", "4. 5"},
    {"1. 90", "2. 100", "3. 110", "4. 120"}
};

// Correct answers for each question
int correctAnswers[NUM_QUESTIONS] = {3, 2, 3, 3, 1, 2, 1, 3, 2, 2};

// Function to display questions and get user answers
void takeQuiz(int* userAnswers, bool* answeredCorrectly) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answeredCorrectly[i]) {
            continue; // Skip already answered questions
        }

        cout << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }

        cout << "Your answer (1-4 or 0 to quit): ";
        int answer;
        cin >> answer;

        if (answer == 0) {
            cout << "Exiting the quiz...\n";
            break; // Exit the quiz
        }

        if (answer == correctAnswers[i]) {
            cout << "Correct!\n";
            answeredCorrectly[i] = true; // Mark as correctly answered
            userAnswers[i] = answer;
        } else {
            cout << "Incorrect. Try again later.\n";
            userAnswers[i] = 0; // Mark as unanswered
        }

        cout << endl;
    }
}

// Function to calculate the score
int calculateScore(bool* answeredCorrectly) {
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answeredCorrectly[i]) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    int userAnswers[NUM_QUESTIONS] = {0};         // Array to store user answers
    bool answeredCorrectly[NUM_QUESTIONS] = {false}; // Array to track correctness

    cout << "Welcome to the Quiz!\n";
    takeQuiz(userAnswers, answeredCorrectly);

    // Calculate and display the score
    int score = calculateScore(answeredCorrectly);
    cout << "\nYou scored " << score << " out of " << NUM_QUESTIONS << "!\n";

    // Retry incorrect answers
    if (score < NUM_QUESTIONS) {
        cout << "\nWould you like to retry the incorrect questions? (y/n): ";
        char retry;
        cin >> retry;

        if (retry == 'y' || retry == 'Y') {
            takeQuiz(userAnswers, answeredCorrectly);
            score = calculateScore(answeredCorrectly);
            cout << "\nAfter retrying, you scored " << score << " out of " << NUM_QUESTIONS << "!\n";
        }
    }

    cout << "Thank you for playing!\n";
    return 0;
}

