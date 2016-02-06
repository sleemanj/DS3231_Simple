#!/bin/bash

function require_clean_work_tree () {

    # Update the index
    git update-index -q --ignore-submodules --refresh
    err=0

    
    # I don't think this is an issue.
    if [ 0 = 1 ]
    then
      # Disallow unstaged changes in the working tree
      if ! git diff-files --quiet --ignore-submodules --
      then
          echo >&2 "You have unstaged changes in your working copy."
          git diff-files --name-status -r --ignore-submodules -- >&2
          err=1
      fi
    fi

    # Disallow uncommitted changes in the index    
    if ! git diff-index --cached --quiet HEAD --ignore-submodules --
    then
        echo >&2 "Your working copy contains uncommitted staged changes."
        git diff-index --cached --name-status -r --ignore-submodules HEAD -- >&2
        err=1
    fi

    if [ $err = 1 ]
    then
        echo >&2 "Please commit or stash them."
        exit 1
    fi
}

require_clean_work_tree

if ! doxygen
then
  echo "Doxygen Failed"
else
  # we need to strip out the absolute link to the class reference
  cat html/index.html | sed -r "s/(href=\")http.*\/[^\/]+\/docs\/html\//\1/" >html/index.html.2
  mv html/index.html.2 html/index.html

  echo "Documentation Build Complete"
  echo "Please check the documentation and if you are satisfied with it hit Y to commit it and update the README.md in the root."
  echo -n "Commit and update README.md (y/N <enter>): "
  read  R
  echo
  if [ "$R" == "y" -o "$R" == "Y" ]
  then
    
    if ( git add . && git commit )
    then
      HEAD="$(git log --format=format:"%h" | head -1)"
      cat ../README.md | sed -r "s/(\(http.*\/)[^\/]+(\/docs\/html\/[^.]+\.html)/\1$HEAD\2/" >../README.md.2
      mv ../README.md.2 ../README.md
      
      echo "Updated documentation link to use $HEAD"      
      echo "You should stage and commit README.md as desired, remember to push!"
    fi
  else
    echo "Cancelled"
  fi
fi