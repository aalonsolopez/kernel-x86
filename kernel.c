void kmain(void) {
	const char *str = "Hello, World!"; // define a string that is a text to display on the screen
	char *video_pointer = (char*)0xb8000; // define a pointer to the video memory address

	unsigned int i = 0;
	unsigned int j = 0;

	// clear video memory by setting all characters to blank
	// the numbers are 80 columns and 25 rows, and each character takes 2 bytes
	while (j < 80 * 25 * 2) {
		// blank character
		video_pointer[j] = ' ';
		// attribute-byte - light grey on black screen
		// 0x07 is the attribute byte, the higher position is the background color, and the lower position is the foreground color
		// 0 is black, 7 is light grey
		video_pointer[j+1] = 0x07;
		// move to the next character, where each character is 2 bytes and every character and style is 4 bytes
		j += 2;
	}

	j = 0;

	// now write the string to the video memory

	while (str[i] != '\0') {
		// the character's ascii
		video_pointer[j] = str[i];
		// attribute-byte - light grey on black screen
		video_pointer[j+1] = 0x07;
		++i;
		j += 2;
	}

	return;
}