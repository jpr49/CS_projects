// Joseph Reyes, Machine Learning - Naive Bayes Classifier
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int DATA = 662; // matches the number of lines in NBA_DataSet.xls
int main() {
	// initialize arrays
	int numYears[DATA] = {}, points[DATA] = {}; double fgPer[DATA] = {}, thrPer[DATA] = {}, ftPer[DATA] = {}; char champ[DATA] = {};
	// output file stream for results
	ofstream fout; fout.open("results.txt");
	fout << "results.txt\nThis file shows the prediction results of naive_bayes.cpp" << endl << endl;
	// temporary vars for reading input file
	string temp; char ctemp;
	// input file stream objects
	ifstream finYR, finFG, fin3PT, finFT, finPTS, finCH;
	// open numYears.txt and store in numYears array
	finYR.open("numYears.txt");
	if (!finYR) { cout << "\"numYears.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!finYR.eof() && count < DATA) { finYR >> temp; numYears[count] = atoi(temp.c_str()); count++; } }
	// open fgPer.txt and store in fgPer array
	finFG.open("fgPer.txt");
	if (!finFG) { cout << "\"fgPer.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!finFG.eof() && count < DATA) { finFG >> temp; fgPer[count] = atof(temp.c_str()); count++; } }
	// open 3PtPer.txt and store in thrPer array
	fin3PT.open("3PtPer.txt");
	if (!fin3PT) { cout << "\"3PtPer.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!fin3PT.eof() && count < DATA) { fin3PT >> temp; thrPer[count] = atof(temp.c_str()); count++; } }
	// open ftPer.txt and store in ftPer array
	finFT.open("ftPer.txt");
	if (!finFT) { cout << "\"ftPer.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!finFT.eof() && count < DATA) { finFT >> temp; ftPer[count] = atof(temp.c_str()); count++; } }
	// open points.txt and store in points array
	finPTS.open("points.txt");
	if (!finPTS) { cout << "\"points.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!finPTS.eof() && count < DATA) { finPTS >> temp; points[count] = atoi(temp.c_str()); count++; } }
	// open champion.txt and store in champ array
	finCH.open("champion.txt");
	if (!finCH) { cout << "\"champion.txt\" is missing. Terminating program." << endl; return -1;
	} else { int count = 0; while (!finCH.eof() && count < DATA) { finCH >> ctemp; champ[count] = ctemp; count++; } }
	// display some historical info
	cout << "NBA historical statistics for thought:\n"
	 	 << "Most number of seasons by a player: 21 (Robert Parish, Kevin Willis)\n"
	 	 << "Highest field gold percentage: 0.670 (DeAndre Jordan)\n"
	 	 << "Highest 3-point field goal percentage: 0.454 (Steve Kerr)\n"
	 	 << "Highest free throw percentage: 0.904 (Steve Nash)\n"
	 	 << "Most points in NBA: 38,387 (Kareem Abdul-Jabbar)" << endl << endl;
	// calculate mean and variance for each feature
	int iSum = 0, iMean = 0, total = 0, squared[DATA] = {}, variance, stdevint;
	double dSum = 0.0, dMean = 0.0, dTotal = 0, dSqrd[DATA] = {}, dVar, dStdev;
	cout << "Some information about the dataset:" << endl;
	// feature 1 - NBA years
	for (int i = 0; i < DATA; i++) { iSum += numYears[i]; }
	iMean = iSum / DATA; cout << "Years in NBA | Mean: " << iMean;
	for (int i = 0; i < DATA; i++) { squared[i] = pow((numYears[i] - iMean), 2); total += squared[i]; }
	variance = total / DATA; cout << " - Variance: " << variance;
	stdevint = sqrt(variance); cout << " - Standard deviation: " << stdevint << endl;
	iMean = 0, iSum = 0, total = 0;
	// feature 2 - field goal percentage
	for (int i = 0; i < DATA; i++) { dSum += fgPer[i]; }
	dMean = dSum / DATA; cout << "FG% | Mean: " << dMean;
	for (int i = 0; i < DATA; i++) { dSqrd[i] = pow((fgPer[i] - dMean), 2); dTotal += dSqrd[i]; }
	dVar = dTotal / DATA; cout << " - Variance: " << dVar;
	dStdev = sqrt(dVar); cout << " - Standard deviation: " << dStdev << endl;
	dMean = 0.0, dSum = 0.0, dTotal = 0;
	// feature 3 - 3-pt field goal percentage
	for (int i = 0; i < DATA; i++) { dSum += thrPer[i]; }
	dMean = dSum / DATA; cout << "3PT% | Mean: " << dMean;
	for (int i = 0; i < DATA; i++) { dSqrd[i] = pow((thrPer[i] - dMean), 2); dTotal += dSqrd[i]; }
	dVar = dTotal / DATA; cout << " - Variance: " << dVar;
	dStdev = sqrt(dVar); cout << " - Standard deviation: " << dStdev << endl;
	dMean = 0.0, dSum = 0.0, dTotal = 0;
	// feature 4 - free throw percentage
	for (int i = 0; i < DATA; i++) { dSum += ftPer[i]; }
	dMean = dSum / DATA; cout << "FT% | Mean: " << dMean;
	for (int i = 0; i < DATA; i++) { dSqrd[i] = pow((ftPer[i] - dMean), 2); dTotal += dSqrd[i]; }
	dVar = dTotal / DATA; cout << " - Variance: " << dVar;
	dStdev = sqrt(dVar); cout << " - Standard deviation: " << dStdev << endl;
	dMean = 0.0, dSum = 0.0, dTotal = 0;
	// feature 5 - points
	for (int i = 0; i < DATA; i++) { iSum += points[i]; }
	iMean = iSum / DATA; cout << "Points | Mean: " << iMean;
	for (int i = 0; i < DATA; i++) { squared[i] = pow((points[i] - iMean), 2); total += squared[i]; }
	variance = total / DATA; cout << " - Variance: " << variance;
	stdevint = sqrt(variance); cout << " - Standard deviation: " << stdevint << endl << endl;
	iMean = 0, iSum = 0, total = 0;
	// discretized arrays for respective values
	int discYRS[DATA] = {}, discFG[DATA] = {}, disc3PT[DATA] = {}, discFT[DATA] = {}, discPTS[DATA] = {};
	// input vars
	int yrs, pts; double fg, thr, ft;
	// discretized target feature vars
	int x1, x2, x3, x4, x5;
	// user input decision
	char choice;
	// counter to detect any invalid input
	int error = 0;
	// comment these out if not working
	system("pause");
	system("cls");
	do {
		cout << "\nThis is a Naive Bayes classifier program.\n"
			 << "Predict whether or not a new entry (player) would\n"
			 << "become a champion in the 2016-2017 season given some stats.\n"
			 << "NBA stats in dataset are based on players' career numbers\n"
			 << "from their rookie years to the 2015-2016 regular season." << endl << endl;
		cout << "NBA season(s) : "; cin >> yrs;
		if (!cin || yrs > 25) { cout << "Invalid value." << endl; cin.clear(); cin.ignore(10000, '\n'); error++; }
		cout << "FG% : "; cin >> fg;
		if (!cin || fg > 1.0) { cout << "Invalid value." << endl; cin.clear(); cin.ignore(10000, '\n'); error++; }
		cout << "3PT% : "; cin >> thr;
		if (!cin || thr > 1.0) { cout << "Invalid value." << endl; cin.clear(); cin.ignore(10000, '\n'); error++; }
		cout << "FT% : "; cin >> ft;
		if (!cin || ft > 1.0) { cout << "Invalid value." << endl; cin.clear(); cin.ignore(10000, '\n'); error++; }
		cout << "Points : "; cin >> pts;
		if (!cin || pts > 40000) { cout << "Invalid value." << endl; cin.clear(); cin.ignore(10000, '\n'); error++; }
		// if there was an encountered invalid value, exit and try again
		if (error != 0) { cout << "\nInvalid input occurred. Restart program again." << endl << endl; break; }
		// if input values are valid, proceed
		// discretize numYears
		for (int i = 0; i < DATA; i++) {
			if (numYears[i] >= 1 && numYears[i] <= 4) { discYRS[i] = 1; }
			if (numYears[i] >= 5 && numYears[i] <= 8) { discYRS[i] = 2; }
			if (numYears[i] >= 9 && numYears[i] <= 12) { discYRS[i] = 3; }
			if (numYears[i] >= 13) { discYRS[i] = 4; }
		}
		// discretize input x1
		if (yrs >= 1 && yrs <= 4) { x1 = 1; }
		if (yrs >= 5 && yrs <= 8) { x1 = 2; }
		if (yrs >= 9 && yrs <= 12) { x1 = 3; }
		if (yrs >= 13 && yrs <= 25) { x1 = 4; }
		// discretize fgPer
		for (int i = 0; i < DATA; i++) {
			if (fgPer[i] >= 0.000 && fgPer[i] <= 0.250) { discFG[i] = 1; }
			if (fgPer[i] >= 0.251 && fgPer[i] <= 0.500) { discFG[i] = 2; }
			if (fgPer[i] >= 0.501 && fgPer[i] <= 0.750) { discFG[i] = 3; }
			if (fgPer[i] >= 0.751 && fgPer[i] <= 1.000) { discFG[i] = 4; }
		}
		// discretize input x2
		if (fg >= 0.000 && fg <= 0.250) { x2 = 1; }
		if (fg >= 0.251 && fg <= 0.500) { x2 = 2; }
		if (fg >= 0.501 && fg <= 0.750) { x2 = 3; }
		if (fg >= 0.751 && fg <= 1.000) { x2 = 4; }
		// discretize thrPer
		for (int i = 0; i < DATA; i++) {
			if (thrPer[i] >= 0.000 && thrPer[i] <= 0.250) { disc3PT[i] = 1; }
			if (thrPer[i] >= 0.251 && thrPer[i] <= 0.500) { disc3PT[i] = 2; }
			if (thrPer[i] >= 0.501 && thrPer[i] <= 0.750) { disc3PT[i] = 3; }
			if (thrPer[i] >= 0.751 && thrPer[i] <= 1.000) { disc3PT[i] = 4; }
		}
		// discretize input x3
		if (thr >= 0.000 && thr <= 0.250) { x3 = 1; }
		if (thr >= 0.251 && thr <= 0.500) { x3 = 2; }
		if (thr >= 0.501 && thr <= 0.750) { x3 = 3; }
		if (thr >= 0.751 && thr <= 1.000) { x3 = 4; }
		// discretize ftPer
		for (int i = 0; i < DATA; i++) {
			if (ftPer[i] >= 0.000 && ftPer[i] <= 0.250) { discFT[i] = 1; }
			if (ftPer[i] >= 0.251 && ftPer[i] <= 0.500) { discFT[i] = 2; }
			if (ftPer[i] >= 0.501 && ftPer[i] <= 0.750) { discFT[i] = 3; }
			if (ftPer[i] >= 0.751 && ftPer[i] <= 1.000) { discFT[i] = 4; }
		}
		// discretize input x4
		if (ft >= 0.000 && ft <= 0.250) { x4 = 1; }
		if (ft >= 0.251 && ft <= 0.500) { x4 = 2; }
		if (ft >= 0.501 && ft <= 0.750) { x4 = 3; }
		if (ft >= 0.751 && ft <= 1.000) { x4 = 4; }
		// discretize points
		for (int i = 0; i < DATA; i++) {
			if (points[i] >= 0 && points[i] <= 4000) { discPTS[i] = 1; }
			if (points[i] >= 4001 && points[i] <= 8000) { discPTS[i] = 2; }
			if (points[i] >= 8001 && points[i] <= 12000) { discPTS[i] = 3; }
			if (points[i] >= 12001) { discPTS[i] = 4; }
		}
		// discretize input x5
		if (pts >= 0 && pts <= 4000) { x5 = 1; }
		if (pts >= 4001 && pts <= 8000) { x5 = 2; }
		if (pts >= 8001 && pts <= 12000) { x5 = 3; }
		if (pts >= 12001) { x5 = 4; }
		cout << "\nYears: " << yrs << " || Discrete value: " << x1 << endl;
		cout << "FG%: " << fg << " || Discrete value: " << x2 << endl;
		cout << "3PT%: " << thr << " || Discrete value: " << x3 << endl;
		cout << "FT%: " << ft << " || Discrete value: " << x4 << endl;
		cout << "Points: " << pts << " || Discrete value: " << x5 << endl;
		// counter vars
		int numY = 0, numN = 0;
		for (int i = 0; i < DATA; i++) { if (champ[i] == 'Y') { numY++; } else { numN++; } }
		cout << "\nNumber of entries: " << DATA << "\nNumber of champions: " << numY << "\nNumber of non-champions: " << numN << endl << endl;
		// class probability vars
		double probY, probN;
		// with Laplace smoothing
		probY = static_cast<double>(numY + 1) / (DATA + 2);
		probN = static_cast<double>(numN + 1) / (DATA + 2);
		cout << "With Laplace smoothing:\nP(Y = \'Y\') = " << probY << endl << "P(Y = \'N\') = " << probN << endl;
		// counter vars to keep track of desired target feature in each array
		int tarX1Y = 0, tarX2Y = 0, tarX3Y = 0, tarX4Y = 0, tarX5Y = 0; // class Y = 'Y'
		int tarX1N = 0, tarX2N = 0, tarX3N = 0, tarX4N = 0, tarX5N = 0; // class Y = 'N'
		// conditional probability vars
		double probX1, probX2, probX3, probX4, probX5;
		// classification vars
		double probClassify_Y, probClassify_N;
		cout << "\nGiven x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << ", x4 = " << x4 << ", x5 = " << x5 << endl;
		// determine P(Y = 'Y' | x)
		for (int i = 0; i < DATA; i++) {
			if (discYRS[i] == x1 && champ[i] == 'Y') { tarX1Y++; }
			if (discFG[i] == x2 && champ[i] == 'Y') { tarX2Y++; }
			if (disc3PT[i] == x3 && champ[i] == 'Y') { tarX3Y++; }
			if (discFT[i] == x4 && champ[i] == 'Y') { tarX4Y++; }
			if (discPTS[i] == x5 && champ[i] == 'Y') { tarX5Y++; }
		}
		// determine P(Y = 'N' | x)
		for (int i = 0; i < DATA; i++) {
			if (discYRS[i] == x1 && champ[i] == 'N') { tarX1N++; }
			if (discFG[i] == x2 && champ[i] == 'N') { tarX2N++; }
			if (disc3PT[i] == x3 && champ[i] == 'N') { tarX3N++; }
			if (discFT[i] == x4 && champ[i] == 'N') { tarX4N++; }
			if (discPTS[i] == x5 && champ[i] == 'N') { tarX5N++; }
		}
		// with Laplace smoothing
		probX1 = static_cast<double>(tarX1Y + 1) / (numY + 2);
		probX2 = static_cast<double>(tarX2Y + 1) / (numY + 2);
		probX3 = static_cast<double>(tarX3Y + 1) / (numY + 2);
		probX4 = static_cast<double>(tarX4Y + 1) / (numY + 2);
		probX5 = static_cast<double>(tarX5Y + 1) / (numY + 2);
		probClassify_Y = probX1 * probX2 * probX3 * probX4 * probX5 * probY;
		cout << "P(Y = 'Y' | x1, x2, x3, x4, x5) = " << probClassify_Y << endl;
		probX1 = static_cast<double>(tarX1N + 1) / (numN + 2);
		probX2 = static_cast<double>(tarX2N + 1) / (numN + 2);
		probX3 = static_cast<double>(tarX3N + 1) / (numN + 2);
		probX4 = static_cast<double>(tarX4N + 1) / (numN + 2);
		probX5 = static_cast<double>(tarX5N + 1) / (numN + 2);
		probClassify_N = probX1 * probX2 * probX3 * probX4 * probX5 * probN;
		cout << "P(Y = 'N' | x1, x2, x3, x4, x5) = " << probClassify_N << endl;
		// classify new entry entered by user
		char predict;
		if (probClassify_Y > probClassify_N) { predict = 'Y'; cout << "\nPredicted class: Y - Champion" << endl; }
		else { predict = 'N'; cout << "\nPredicted class: N - Non-champion" << endl; }
		cout << "\nPrediction results in \"results.txt\"" << endl;
		// store prediction result in output file
		fout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << ", x4 = " << x4 << ", x5 = " << x5 << " | Y = \'" << predict << "\'" << endl;
		cout << "\nTry another round? (press 'Y', or press any key to exit) : "; cin >> choice;
		// clear the console for new round
		system("cls"); // comment out if not working
	} while (choice == 'Y' || choice == 'y');
	// else leave and close program
	cout << "Exiting program... Goodbye!" << endl;
	// close file stream objects
	finYR.close(); finFG.close(); fin3PT.close(); finFT.close(); finPTS.close(); finCH.close(); fout.close();
	// wait for key to exit executable
	system("pause"); // comment out if not working
	return 0;
}
