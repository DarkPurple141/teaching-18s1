<template lang="html">
   <section class="section-header">
      <h1>{{ longName }}</h1>
   </section>
</template>

<script>
export default {
   props: {
      name: String
   },

   computed: {
      longName() {
         return this.name.toUpperCase()
      }
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';

.section-header {
   display: flex;
   align-items: center;
   justify-content: flex-start;
   color: @primary-text;
   font-size: 64px;
   margin-left: 20px;
}

h1 {
   border-left: 10px solid @accent;
   padding: 30px;
   margin: auto 0;
}

@media screen and (max-width: 600px) {
   h1 {
      font-size: 44px;
   }
}

</style>
