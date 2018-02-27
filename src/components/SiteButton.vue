<template lang="html">
   <div @click="$router.push({ name: 'Class', params: { class: path } })" class='button -blue center'>
      <h3>{{ text }}</h3>
   </div>
</template>

<script>
export default {
   props: {
      text: String,
      path: String
   }
}
</script>

<style scoped lang="less">
@import '../assets/colors.less';

.button {
   margin: 10px;
   min-width: 200px;
   width: 50%;
  -webkit-transition: opacity 300ms linear;
  transition: opacity 300ms linear;
  display: -webkit-box;
  display: -ms-flexbox;
  display: flex;
  overflow: hidden;
  padding: 12px 12px;
  cursor: pointer;
  -webkit-user-select: none;
     -moz-user-select: none;
      -ms-user-select: none;
          user-select: none;
  -webkit-transition: all 150ms linear;
  transition: all 150ms linear;
  text-align: center;
  white-space: nowrap;
  text-decoration: none !important;
  text-transform: none;
  text-transform: capitalize;
  color: #fff;
  border: 0 none;
  border-radius: 4px;
  font-size: 13px;
  font-weight: 500;
  line-height: 1.3;
  -webkit-appearance: none;
  -moz-appearance: none;
  appearance: none;
  -webkit-box-pack: center;
      -ms-flex-pack: center;
          justify-content: center;
  -webkit-box-align: center;
      -ms-flex-align: center;
          align-items: center;
  -webkit-box-flex: 0;
      -ms-flex: 0 0 160px;
          flex: 0 0 160px;
  -webkit-box-shadow: 2px 5px 10px #aaa;
          box-shadow: 2px 5px 10px #aaa;

    h3 {
       margin: 10px;
       color: #eee;
       font-size: 36px;
    }
}


.button:hover {
  -webkit-transition: all 150ms linear;
  transition: all 150ms linear;
  opacity: .85;
}
.button:active {
  -webkit-transition: all 150ms linear;
  transition: all 150ms linear;
  opacity: .75;
}
.button:focus {
  outline: 1px dotted #959595;
  outline-offset: -4px;
}

.button.-blue {
  background: @accent;
}

@media screen and (max-width: 600px) {
   .button {
      min-width: 80px;
      max-width: 125px;
      h3 {
         font-size: 24px;
      }
   }
}


</style>
