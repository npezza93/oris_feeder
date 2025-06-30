libs:
	@echo "Installing libraries..."
	@while IFS= read -r lib || [ -n "$$lib" ]; do \
		if [ -n "$$lib" ]; then \
			echo "Installing $$lib..."; \
			arduino-cli lib install "$$lib"; \
		fi \
	done < libraries.txt
